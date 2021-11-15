#include <iostream>
#include <vector>

//ROOT header
#include "TRandom.h"
#include "TH1.h"
#include "TTree.h"
#include "TCanvas.h"
#include "TLorentzVector.h"
#include "TVector.h"

//CUSTOM header
#include "Datum.h"

int main() {

	//c=1: mass, momentum, energy in MeV; B meson decay in Kaon+Pion
	

	//mass of particles, P=pion B=Bmeson K=Kaon
	const double m_P = 140., m_B = 5279., m_K = 500.;

	//Lorentz BOOST to LAB (B meson four momentum in LAB)
	const TLorentzVector LAB(300., 0., 0., sqrt(300. * 300. + m_B * m_B));
	//three velocity vector of LAB
	const TVector3 v=LAB.BoostVector();

	//COM three-momentum magnitude of back to back particle
	double COMp3 = (sqrt((m_P * m_P * m_P * m_P + m_B * m_B * m_B * m_B + m_K * m_K * m_K * m_K - 2 * m_P * m_P * m_B * m_B - 2 * m_P * m_P * m_K * m_K - 2 * m_B * m_B * m_K * m_K) * (1 / (4 * m_B * m_B))));

	//particles four-momenta
	TLorentzVector p4_P, p4_B, p4_K;

	//vector of four momenta
	std::vector<TLorentzVector> p4_v;
	p4_v.push_back(p4_P); p4_v.push_back(p4_K); p4_v.push_back(p4_B);


	//Gaussian resolution
	std::vector<double> resol;
	resol.push_back(0.1); resol.push_back(0.2); resol.push_back(0.3); resol.push_back(0.5);


	// number of simulated measurements
	int nmeas = 1000;

	//random generator...
	TRandom* gen = new TRandom();
	//...exploiting the machine clock for the seed
	gen->SetSeed(0);


	//number of bins in histogram
	int nbins = nmeas;

	//histogram of Kaon+Pion invariant mass
	double imKP;
	TH1F HimKP("hist_inv_mass_KP", "Distribution of invariant mass of Kaon+Pion", nbins, 0.5 * m_B, 1.5 * m_B);

	//histogram of Kaon+Pion invariant mass
	double angleKP;
	TH1F HangleKP("hist_angle_KP", "Distribution of angle between Kaon and Pion", nbins, 0, 2*3.14);


	//generic three vector (dummy variable)
	TVector3 v3;
	//generic four momentum (dummy variable)
	TLorentzVector p4;
	//component of generic four momentum (dummy variable)
	double px, py, pz, E;
	//component of a generic measure (dummy variable)
	Datum datum_x; Datum datum_y; Datum datum_z; Datum datum_t;


	//Tree of COM momenta
	TTree* COMtree = new TTree("COM_momenta_tree", "tree containing COM momenta");
	COMtree->Branch("COMp4_P", &p4_P, "COM momentum of pion/D");
	COMtree->Branch("COMp4_K", &p4_K, "COM momentum of Kaon/D");
	COMtree->Branch("COMp4_B", &p4_B, "COM momentum of B meson/D");

	//Tree of LAB momenta
	TTree* LABtree = new TTree("LAB_momenta_tree", "tree containing LAB momenta");
	LABtree->Branch("LABp4_P", &p4_P, "LAB momentum of pion/D");
	LABtree->Branch("LABp4_K", &p4_K, "LAB momentum of Kaon/D");
	LABtree->Branch("LABp4_B", &p4_B, "LAB momentum of B meson/D");

	//measure
	std::vector<TTree*> meas;

	//Tree of LAB measurement momenta
	//Pion
	TTree* mLABpion = new TTree("LAB_measured_momenta_tree", "tree containing LAB measured momenta");
	mLABpion->Branch("meas", &datum_x, "LAB measured p_x");
	mLABpion->Branch("meas", &datum_y, "LAB measured p_y");
	mLABpion->Branch("meas", &datum_z, "LAB measured p_z");
	mLABpion->Branch("meas", &datum_t, "LAB measured p_t");
	//Kaon
	TTree* mLABkaon = new TTree("LAB_measured_momenta_tree", "tree containing LAB measured momenta");
	mLABkaon->Branch("meas", &datum_x, "LAB measured p_x");
	mLABkaon->Branch("meas", &datum_y, "LAB measured p_y");
	mLABkaon->Branch("meas", &datum_z, "LAB measured p_z");
	mLABkaon->Branch("meas", &datum_t, "LAB measured p_t");
	//Bmeson
	TTree* mLABBmeson = new TTree("LAB_measured_momenta_tree", "tree containing LAB measured momenta");
	mLABBmeson->Branch("meas", &datum_x, "LAB measured p_x");
	mLABBmeson->Branch("meas", &datum_y, "LAB measured p_y");
	mLABBmeson->Branch("meas", &datum_z, "LAB measured p_z");
	mLABBmeson->Branch("meas", &datum_t, "LAB measured p_t");

	meas.push_back(mLABpion); meas.push_back(mLABkaon); meas.push_back(mLABBmeson); //the order P-K-B matters!

	for (int i = 0; i < nmeas; i++) {
		
		//generating random vector of magnitude p
		gen->Sphere(px, py, pz, COMp3);

		//setting COM momenta
		E = sqrt(COMp3 * COMp3 + m_P * m_P);
		p4_P.SetPxPyPzE(px, py, pz, E);

		E = sqrt(COMp3 * COMp3 + m_K * m_K);
		p4_K.SetPxPyPzE(-px, -py, -pz, E);

		p4_B.SetPxPyPzE(0., 0., 0., m_B);

		//saving COM momenta in COMtree
		COMtree->Fill();

		//Lorentz BOOST
		p4_B.Boost(v);
		p4_P.Boost(v);
		p4_K.Boost(v);

		//saving LAB momenta in LABtree
		LABtree->Fill();

		//histogram of Kaon+Pion invariant mass
		p4 = p4_P + p4_K;
		imKP = p4.Mag();
		HimKP.Fill(imKP);

		//histogram of angle between Kaon and Piaon
		v3 = p4_K.Vect();
		angleKP = p4_P.Angle(v3);
		HangleKP.Fill(angleKP);

		//measurement
		int j = 0;
		for (std::vector<TLorentzVector>::const_iterator it = p4_v.begin(); it != p4_v.end(); ++it) {

			//creating measurments for pion
			datum_x.SetValue(it->X()); datum_x.SetError(it->X()*resol[1]);
			datum_y.SetValue(it->Y()); datum_y.SetError(it->Y()* resol[1]);
			datum_z.SetValue(it->Z()); datum_z.SetError(it->Z()* resol[1]);
			datum_t.SetValue(it->T()); datum_z.SetError(it->T()* resol[1]);

			//filling respectively tree
			meas[j]->Fill();
			j++;

		}

	}

	//plotting histogram
	TCanvas Canv("Canv", "Canvas for plotting", 1280, 1024);
	
	//invarinat mass of Kaon+Pion
	HimKP.GetXaxis()->SetTitle("Invariant mass of Kaon+Pion [MeV]");
	HimKP.Draw();
	//save pdf file
	Canv.SaveAs("./true-mass.pdf");

	//angle between Kaon nad Pion
	HangleKP.GetXaxis()->SetTitle("Angle between Kaon and Pion [rad]");
	HangleKP.Draw();
	//save pdf file
	Canv.SaveAs("./opening-angle.pdf");

	// Clean up
	delete gen;
	delete COMtree;
	delete LABtree;
	delete mLABpion;
	delete mLABkaon;
	delete mLABBmeson;

	return 0;
};