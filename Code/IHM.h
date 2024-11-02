#pragma once
#include "DemandeTransport.h"
namespace SATRAP {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de IHM
	/// </summary>
	public ref class IHM : public System::Windows::Forms::Form
	{
	private:
		DemandeTransport *Demande;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  Histogramme;
	private: System::Windows::Forms::Label^  Statut;
	private: System::Windows::Forms::Label^  Message;
	private: System::Windows::Forms::Label^  Chargement;
	private: System::Windows::Forms::Label^  MessageMag;

			 BddAdapteur *bdd;
	public:
		IHM(void)
		{
			InitializeComponent();
			this->RepfinChargement->Visible = false;
			MessageMag->Visible = true;
			Message->Visible = true;
			Statut->Visible = true;
			LbDemande3->Visible = false;
			Chargement->Visible = false;
			DureeMoyenne->Visible = false;
			this->RepfinChargement->Visible = true;
			this->RepFinDechargement->Visible = false;
			Histogramme->Visible = false;
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}

		//////////////////://////////////////////////://
		//////// Fonction d'IHM ////////////////////////
		////////////////////////////////////////////////
		void AfficherStatutDemande(String^ message)
		{
			LbDemande->Text = message;
			LbDemande->Visible = true;
			
		}
		void AfficherMessage(int a)
		{
			if (a == 1) {
				Chargement->Visible = true;
			}
			else if (a == 2) 
			{
				LbDemande3->Visible = true;
			}

		}
		
		//////////////////////////////////////////////////

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~IHM()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^  tabControl1;
	protected:
	private: System::Windows::Forms::TabPage^  IHMOperateur;
	private: System::Windows::Forms::Button^  RequetteTransport;
	private: System::Windows::Forms::TabPage^  IHMRespAtelier;
	private: System::Windows::Forms::TabPage^  MagAdapteur;
	private: System::Windows::Forms::Label^  LbDemande;
	private: System::Windows::Forms::Button^  RepfinChargement;
	private: System::Windows::Forms::Button^  RepFinDechargement;

	private: System::Windows::Forms::Label^  LbDemande3;

	private: System::Windows::Forms::Button^  DureeMoyenne;
	private: System::Windows::Forms::Button^  ReqNbRequetesOp;

	private: System::Windows::Forms::Button^  ReqDureeMoyenne;








	private:
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->IHMOperateur = (gcnew System::Windows::Forms::TabPage());
			this->Statut = (gcnew System::Windows::Forms::Label());
			this->Message = (gcnew System::Windows::Forms::Label());
			this->Chargement = (gcnew System::Windows::Forms::Label());
			this->RepfinChargement = (gcnew System::Windows::Forms::Button());
			this->LbDemande = (gcnew System::Windows::Forms::Label());
			this->RequetteTransport = (gcnew System::Windows::Forms::Button());
			this->IHMRespAtelier = (gcnew System::Windows::Forms::TabPage());
			this->Histogramme = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->ReqNbRequetesOp = (gcnew System::Windows::Forms::Button());
			this->ReqDureeMoyenne = (gcnew System::Windows::Forms::Button());
			this->DureeMoyenne = (gcnew System::Windows::Forms::Button());
			this->MagAdapteur = (gcnew System::Windows::Forms::TabPage());
			this->MessageMag = (gcnew System::Windows::Forms::Label());
			this->RepFinDechargement = (gcnew System::Windows::Forms::Button());
			this->LbDemande3 = (gcnew System::Windows::Forms::Label());
			this->tabControl1->SuspendLayout();
			this->IHMOperateur->SuspendLayout();
			this->IHMRespAtelier->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Histogramme))->BeginInit();
			this->MagAdapteur->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->IHMOperateur);
			this->tabControl1->Controls->Add(this->IHMRespAtelier);
			this->tabControl1->Controls->Add(this->MagAdapteur);
			this->tabControl1->Location = System::Drawing::Point(3, 5);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(546, 402);
			this->tabControl1->TabIndex = 0;
			// 
			// IHMOperateur
			// 
			this->IHMOperateur->BackColor = System::Drawing::Color::DarkCyan;
			this->IHMOperateur->Controls->Add(this->Statut);
			this->IHMOperateur->Controls->Add(this->Message);
			this->IHMOperateur->Controls->Add(this->Chargement);
			this->IHMOperateur->Controls->Add(this->RepfinChargement);
			this->IHMOperateur->Controls->Add(this->LbDemande);
			this->IHMOperateur->Controls->Add(this->RequetteTransport);
			this->IHMOperateur->Location = System::Drawing::Point(4, 22);
			this->IHMOperateur->Name = L"IHMOperateur";
			this->IHMOperateur->Padding = System::Windows::Forms::Padding(3);
			this->IHMOperateur->Size = System::Drawing::Size(538, 376);
			this->IHMOperateur->TabIndex = 0;
			this->IHMOperateur->Text = L"IHMOperateur";
			this->IHMOperateur->Click += gcnew System::EventHandler(this, &IHM::IHMOperateur_Click);
			// 
			// Statut
			// 
			this->Statut->AutoSize = true;
			this->Statut->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->Statut->Location = System::Drawing::Point(35, 81);
			this->Statut->Name = L"Statut";
			this->Statut->Size = System::Drawing::Size(64, 20);
			this->Statut->TabIndex = 5;
			this->Statut->Text = L"Statut:";
			// 
			// Message
			// 
			this->Message->AutoSize = true;
			this->Message->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->Message->Location = System::Drawing::Point(35, 215);
			this->Message->Name = L"Message";
			this->Message->Size = System::Drawing::Size(81, 20);
			this->Message->TabIndex = 4;
			this->Message->Text = L"Message";
			// 
			// Chargement
			// 
			this->Chargement->AutoSize = true;
			this->Chargement->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Chargement->Location = System::Drawing::Point(35, 248);
			this->Chargement->Name = L"Chargement";
			this->Chargement->Size = System::Drawing::Size(220, 24);
			this->Chargement->TabIndex = 3;
			this->Chargement->Text = L"Demande Chargement";
			// 
			// RepfinChargement
			// 
			this->RepfinChargement->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->RepfinChargement->Location = System::Drawing::Point(294, 215);
			this->RepfinChargement->Name = L"RepfinChargement";
			this->RepfinChargement->Size = System::Drawing::Size(173, 57);
			this->RepfinChargement->TabIndex = 2;
			this->RepfinChargement->Text = L"RepfinChargement";
			this->RepfinChargement->UseVisualStyleBackColor = true;
			this->RepfinChargement->Click += gcnew System::EventHandler(this, &IHM::RepfinChargement_Click);
			// 
			// LbDemande
			// 
			this->LbDemande->AutoSize = true;
			this->LbDemande->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbDemande->Location = System::Drawing::Point(35, 108);
			this->LbDemande->Name = L"LbDemande";
			this->LbDemande->Size = System::Drawing::Size(162, 24);
			this->LbDemande->TabIndex = 1;
			this->LbDemande->Text = L"Prise en compte";
			this->LbDemande->Visible = false;
			this->LbDemande->Click += gcnew System::EventHandler(this, &IHM::label1_Click);
			// 
			// RequetteTransport
			// 
			this->RequetteTransport->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->RequetteTransport->Location = System::Drawing::Point(294, 81);
			this->RequetteTransport->Name = L"RequetteTransport";
			this->RequetteTransport->Size = System::Drawing::Size(173, 51);
			this->RequetteTransport->TabIndex = 0;
			this->RequetteTransport->Text = L"RequetteTransport";
			this->RequetteTransport->UseVisualStyleBackColor = true;
			this->RequetteTransport->Click += gcnew System::EventHandler(this, &IHM::RequetteTransport_Click);
			// 
			// IHMRespAtelier
			// 
			this->IHMRespAtelier->BackColor = System::Drawing::Color::DarkSeaGreen;
			this->IHMRespAtelier->Controls->Add(this->Histogramme);
			this->IHMRespAtelier->Controls->Add(this->ReqNbRequetesOp);
			this->IHMRespAtelier->Controls->Add(this->ReqDureeMoyenne);
			this->IHMRespAtelier->Controls->Add(this->DureeMoyenne);
			this->IHMRespAtelier->Location = System::Drawing::Point(4, 22);
			this->IHMRespAtelier->Name = L"IHMRespAtelier";
			this->IHMRespAtelier->Padding = System::Windows::Forms::Padding(3);
			this->IHMRespAtelier->Size = System::Drawing::Size(538, 376);
			this->IHMRespAtelier->TabIndex = 1;
			this->IHMRespAtelier->Text = L"IHMRespAtelier";
			this->IHMRespAtelier->Click += gcnew System::EventHandler(this, &IHM::IHMRespAtelier_Click);
			// 
			// Histogramme
			// 
			chartArea1->Name = L"ChartArea1";
			this->Histogramme->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->Histogramme->Legends->Add(legend1);
			this->Histogramme->Location = System::Drawing::Point(9, 127);
			this->Histogramme->Name = L"Histogramme";
			series1->ChartArea = L"ChartArea1";
			series1->Legend = L"Legend1";
			series1->Name = L"Series1";
			this->Histogramme->Series->Add(series1);
			this->Histogramme->Size = System::Drawing::Size(523, 231);
			this->Histogramme->TabIndex = 6;
			this->Histogramme->Text = L"chart1";
			this->Histogramme->Click += gcnew System::EventHandler(this, &IHM::Histogramme_Click);
			// 
			// ReqNbRequetesOp
			// 
			this->ReqNbRequetesOp->Location = System::Drawing::Point(256, 6);
			this->ReqNbRequetesOp->Name = L"ReqNbRequetesOp";
			this->ReqNbRequetesOp->Size = System::Drawing::Size(165, 60);
			this->ReqNbRequetesOp->TabIndex = 5;
			this->ReqNbRequetesOp->Text = L"ReqNbRequetesOp";
			this->ReqNbRequetesOp->UseVisualStyleBackColor = true;
			this->ReqNbRequetesOp->Click += gcnew System::EventHandler(this, &IHM::ReqNbRequetesOp_Click);
			// 
			// ReqDureeMoyenne
			// 
			this->ReqDureeMoyenne->Location = System::Drawing::Point(36, 6);
			this->ReqDureeMoyenne->Name = L"ReqDureeMoyenne";
			this->ReqDureeMoyenne->Size = System::Drawing::Size(151, 60);
			this->ReqDureeMoyenne->TabIndex = 4;
			this->ReqDureeMoyenne->Text = L"ReqDureeMoyenne";
			this->ReqDureeMoyenne->UseVisualStyleBackColor = true;
			this->ReqDureeMoyenne->Click += gcnew System::EventHandler(this, &IHM::button1_Click_2);
			// 
			// DureeMoyenne
			// 
			this->DureeMoyenne->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->DureeMoyenne->Location = System::Drawing::Point(24, 72);
			this->DureeMoyenne->Name = L"DureeMoyenne";
			this->DureeMoyenne->Size = System::Drawing::Size(422, 49);
			this->DureeMoyenne->TabIndex = 3;
			this->DureeMoyenne->Text = L"DureeMoyenne";
			this->DureeMoyenne->UseVisualStyleBackColor = true;
			this->DureeMoyenne->Click += gcnew System::EventHandler(this, &IHM::button1_Click_1);
			// 
			// MagAdapteur
			// 
			this->MagAdapteur->BackColor = System::Drawing::Color::LightGreen;
			this->MagAdapteur->Controls->Add(this->MessageMag);
			this->MagAdapteur->Controls->Add(this->RepFinDechargement);
			this->MagAdapteur->Controls->Add(this->LbDemande3);
			this->MagAdapteur->ForeColor = System::Drawing::SystemColors::ControlText;
			this->MagAdapteur->Location = System::Drawing::Point(4, 22);
			this->MagAdapteur->Name = L"MagAdapteur";
			this->MagAdapteur->Padding = System::Windows::Forms::Padding(3);
			this->MagAdapteur->Size = System::Drawing::Size(538, 376);
			this->MagAdapteur->TabIndex = 2;
			this->MagAdapteur->Text = L"MagAdapteur";
			// 
			// MessageMag
			// 
			this->MessageMag->AutoSize = true;
			this->MessageMag->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->MessageMag->Location = System::Drawing::Point(41, 111);
			this->MessageMag->Name = L"MessageMag";
			this->MessageMag->Size = System::Drawing::Size(86, 20);
			this->MessageMag->TabIndex = 2;
			this->MessageMag->Text = L"Message:";
			// 
			// RepFinDechargement
			// 
			this->RepFinDechargement->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->RepFinDechargement->Location = System::Drawing::Point(303, 111);
			this->RepFinDechargement->Name = L"RepFinDechargement";
			this->RepFinDechargement->Size = System::Drawing::Size(226, 61);
			this->RepFinDechargement->TabIndex = 1;
			this->RepFinDechargement->Text = L"RepFinDechargement";
			this->RepFinDechargement->UseVisualStyleBackColor = true;
			this->RepFinDechargement->Click += gcnew System::EventHandler(this, &IHM::button1_Click);
			// 
			// LbDemande3
			// 
			this->LbDemande3->AutoSize = true;
			this->LbDemande3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbDemande3->Location = System::Drawing::Point(37, 148);
			this->LbDemande3->Name = L"LbDemande3";
			this->LbDemande3->Size = System::Drawing::Size(243, 24);
			this->LbDemande3->TabIndex = 0;
			this->LbDemande3->Text = L"Demande Dechargement";
			this->LbDemande3->UseMnemonic = false;
			this->LbDemande3->Click += gcnew System::EventHandler(this, &IHM::label1_Click_1);
			// 
			// IHM
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(548, 405);
			this->Controls->Add(this->tabControl1);
			this->Name = L"IHM";
			this->Text = L"IHM";
			this->Load += gcnew System::EventHandler(this, &IHM::IHM_Load);
			this->tabControl1->ResumeLayout(false);
			this->IHMOperateur->ResumeLayout(false);
			this->IHMOperateur->PerformLayout();
			this->IHMRespAtelier->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Histogramme))->EndInit();
			this->MagAdapteur->ResumeLayout(false);
			this->MagAdapteur->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void RequetteTransport_Click(System::Object^  sender, System::EventArgs^  e) {
	
	AfficherStatutDemande("Prise en compte ");
	this->Demande = new DemandeTransport();
		
	
	
	char robotStatus[256];
	strcpy(robotStatus, "Stopped");
	Sleep(1000);
	strcpy(robotStatus, Demande->getRobot()->getStatus());

	while (strcmp(robotStatus, "Going to Telma") == 0)//|| strcmp(robotStatus, "Driving into dock") == 0)
	{
		strcpy(robotStatus, Demande->getRobot()->getStatus());
		Sleep(1000);
	}
	if (strcmp(robotStatus, "Arrived at Telma") == 0)
	{
		
		
		this->RequetteTransport->Visible = false;
		this->RepfinChargement->Visible = true;
		Chargement->Visible = true;
		//AfficherMessage(1);
		//this->RepfinChargement->Visible = true;
		

	}
	
	
}
private: System::Void IHMOperateur_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void RepfinChargement_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Demande->getRobot()->goToGoal("WALLAH");
	this->Demande->getBdd()->ExecRequete("RequeteSQLUpdateDemande1");
	char robotStatus[256];
	
	strcpy(robotStatus, "Stopped");
	Sleep(1000);

	strcpy(robotStatus, Demande->getRobot()->getStatus());
	
	while (strcmp(robotStatus, "Going to WALLAH") == 0)//|| strcmp(robotStatus, "Driving into dock") == 0)
	{
		strcpy(robotStatus, Demande->getRobot()->getStatus());
		Sleep(1000);
	}
	if (strcmp(robotStatus, "Arrived at WALLAH") == 0)
	{
		
		
		this->RequetteTransport->Visible = false;
		this->RepfinChargement->Visible = false;
		this->RepFinDechargement->Visible = true;
		AfficherMessage(2);

	}

}
private: System::Void label1_Click_1(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Demande->getBdd()->ExecRequete("RequeteSQLUpdateDemande2");
	this->Demande->getRobot()->goToDock();
	AfficherStatutDemande("opération réalisée ");
	this->RequetteTransport->Visible = true;
	//delete Demande;
}
private: System::Void NombreRequeteOp_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void DureeMoyenne_Click(System::Object^  sender, System::EventArgs^  e) {

}

private: System::Void button1_Click_1(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void IHMRespAtelier_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void button1_Click_2(System::Object^  sender, System::EventArgs^  e) {
	Histogramme->Visible = false;
	bdd = new BddAdapteur();
	float valeur;
	valeur = bdd->ReqDureeMoyenne();
	String^ valeurEnChaine = valeur.ToString();
	this->DureeMoyenne->Text = "Duree moyenne en (secondes) = " + valeurEnChaine;
	DureeMoyenne->Visible = true;

}
private: System::Void ReqNbRequetesOp_Click(System::Object^  sender, System::EventArgs^  e) {
	DureeMoyenne->Visible = false;
	Histogramme->Visible = true;
	std::vector<OperateurTransport> operatorsData = bdd->RepNbrequete();
	// Effacez les séries précédentes pour éviter l'accumulation des données
	this->Histogramme->Series->Clear();
	// Ajoutez une série à l'histogramme
	this->Histogramme->Series->Add("Nombre de requetes");
	this->Histogramme->Series["Nombre de requetes"]->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Column;
	// Ajoutez des points de données pour chaque opérateur
	for (const auto& operatorData : operatorsData) {
		this->Histogramme->Series["Nombre de requetes"]->Points->AddXY(gcnew String(operatorData.getNom().c_str()), operatorData.getNb());
	}
	// Définissez le titre des axes
	this->Histogramme->ChartAreas[0]->AxisX->Title = "Opérateurs"; 
	this->Histogramme->ChartAreas[0]->AxisY->Title = "Nombre de requêtes";

	// Affichez l'histogramme
	this->Histogramme->Visible = true;
	DureeMoyenne->Visible = false;

}	
		 
private: System::Void IHM_Load(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void Histogramme_Click(System::Object^  sender, System::EventArgs^  e) {
}
};
}

