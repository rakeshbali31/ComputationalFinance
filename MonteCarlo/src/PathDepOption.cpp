//
// Created by Rakesh Bali on 05/06/2024.
//

#include <PathDepOption.h>
#include <AsianOption.h>

void GetZ(std::vector<double>& Z, SamplePath& S, double S0,
          double r, double sigma, double dt) {
    int m = S.size();
    Z[0] = (log(S[0]/S0) - (r-0.5*sigma*sigma)*dt) / (sigma * sqrt(dt));
    for(int i=1; i<m; i++) {
        Z[i] = (log(S[i]/S[i-1]) - (r-0.5*sigma*sigma)*dt) / (sigma * sqrt(dt));
    }

}

void Rescale(SamplePath& S, std::vector<double>& Z, double S0,
            double r, double sigma, double dt)
{
    int m=S.size();
    S[0] = S0*exp((r-sigma*sigma/2.0)*dt + sigma*sqrt(dt)*Z[0]);
    for (int j=1; j<m; j++)
    {
        S[j] = S[j-1]*exp((r-sigma*sigma/2.0)*dt + sigma*sqrt(dt)*Z[j]);
    }
}

double PathDepOption::PriceByMC(BSModel Model, long N, double epsilon) {
    double H=0.0, Hsq=0.0, Hdelta=0.0, Hrho=0.0, Hvega=0.0, Htheta=0.0, Hgamma=0.0;
    double S0=Model.get_s0(), r=Model.get_r(), sigma=Model.get_sigma(), dt=T/m;

    std::vector<double> Z(m);
    SamplePath S(m);

    for(long i=0; i<N; i++) {
        Model.GenerateSamplePath(T, m, S);
        H = (i*H + Payoff(S))/(i+1.0);
        Hsq = (i*Hsq + pow(Payoff(S),2.0)) / (i+1.0);

        GetZ(Z,S,S0,r,sigma,dt);


        Rescale(S,Z,S0*(1.0+epsilon),r,sigma,dt);
        Hdelta = (i*Hdelta + Payoff(S))/(i+1.0);

        Rescale(S,Z,S0*(1.0-epsilon),r,sigma,dt);
        Hgamma = (i*Hgamma + Payoff(S))/(i+1.0);

        Rescale(S,Z,S0,r,sigma,dt*(1+epsilon));
        Htheta = (i*Htheta + Payoff(S))/(i+1.0);

        Rescale(S,Z,S0,r,sigma*(1+epsilon),dt);
        Hvega = (i*Hvega + Payoff(S))/(i+1.0);

        Rescale(S,Z,S0,r*(1+epsilon),sigma,dt);
        Hrho = (i*Hrho + Payoff(S))/(i+1.0);
    }
    Price = exp(-r*T)*H;
    PricingError = exp(-r*T)*sqrt(Hsq - H*H) / sqrt(N-1.0);

    delta = exp(-r*T)*(Hdelta-H)/(S0*epsilon);
    gamma =  exp(-r*T) * (Hdelta - 2*H + Hgamma) / (S0*S0*epsilon*epsilon);
    vega = exp(-r*T) * (Hvega - H) / (sigma*epsilon);
    rho = (exp(-r*(1+epsilon)*T) * Hrho - exp(-r*T) * H) / r*(epsilon);
    theta = -(exp(-r*T*(1+epsilon)) * Htheta - (exp(-r*T) * H))/ T*(epsilon);
    return Price;
}

double PathDepOption::PriceByVarRedMC(BSModel Model, long N, PathDepOption &CVOption) {
    DifferenceOfOptions VarRedOpt(T,m,this,&CVOption);
    double price = VarRedOpt.PriceByMC(Model,N, 0.0001) + CVOption.PriceByBSFormula(Model);
    set_price(price);
    set_pricing_error(VarRedOpt.get_pricing_error());
    return price;
}
