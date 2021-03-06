{
  c1 = new TCanvas("c1","A graph with error bars");
   c1->SetGrid();
   c1->GetFrame()->SetFillColor(21);
   c1->GetFrame()->SetBorderSize(12);
   const Int_t n = 10; //number of data points
   Double_t x[n]  ={6.71968629257381,
6.74094388836407,
6.91610769079247,
6.99067313138421,
7.02292201803151,
7.06299100693838,
7.19177868655861,
7.25131546878746,
7.30891710853265,
7.37975720786768,


}; //x values
  
   Double_t y[n] = {-8.51719319141624,
-8.11172808330807,
-7.70626297519991,
-7.26443022292087,
-7.13089883029635,
-7.01311579463996,
-4.26869794936688,
-4.01738352108597,
-3.81671282562382,
-3.57555076880693,

}; //y values

   
   Double_t ex[n] ={0.004351463858397,
0.004353146297835,
0.004387283723384,
0.004411244827514,
0.004421037051977,
0.004433126820491,
0.004454290398037,
0.004452089782385,
0.00444060917365,
0.004417144513226,



}; //error of x values
   
   Double_t ey[n] ={0.25,
0.166666666666667,
0.111111111111111,
0.071428571428572,
0.0625,
0.055555555555556,
0.142857142857143,
0.111111111111111,
0.090909090909091,
0.071428571428572,

}; //error of y values

   
   gr = new TGraphErrors(n,x,y,ex,ey);
   gr->SetTitle(";log(T);log(V_s)");
   gr->SetMarkerColor(4);
   gr->SetMarkerStyle(21);
   gr->Draw("AP");
   
   TF1 *f = new TF1("f","x*[1]+[0]");
   f->SetLineColor(kRed+0);
   f->SetParameters(1, 1);
   gr->Fit("f");
   gStyle->SetOptStat(111110);
   gStyle->SetOptFit(1111);


   return c1;
}
