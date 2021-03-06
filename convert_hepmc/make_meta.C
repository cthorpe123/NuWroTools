//inputs 
//metafile = POTInfo.txt file generated by nuwro
//eventcout

void make_meta(std::string metafile , std::string eventcount , std::string outdir){

	double POT_Per_Event;
	bool found_POT=false;

	int events;
	double POT=0;

	std::ifstream pot_input(metafile);

	std::string line;

	while( getline(pot_input,line) ){

		//get the line that starts with "Total POT: " 
		if( line.find("Total POT: ",0) != std::string::npos ){
			POT = atof(line.substr(10).c_str());
			found_POT=true;
			std::cout <<"Using total POT = " << POT << std::endl;

		}

	}

	pot_input.close();

	//get the number of events processed

	std::ifstream count(eventcount);

	count >> events;

	std::cout << "events=" << events << std::endl;

	//calculate POT per event
	std::cout << "Using POT per event =  " << POT/events << std::endl;

	count.close();	

	//write POT per event to file
	std::ofstream output(outdir + "hepmc_POT.meta");

	output << "POT_Per_Event=" << POT/events << std::endl;
	
}
