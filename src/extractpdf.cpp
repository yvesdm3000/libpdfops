#include <PdfOps.h>

#include <stdio.h>
#include <unistd.h>

int usage(const char* arg0)
{
	printf("Usage: %s [-f firstpage] [-l lastpage] [-h] inputPage.pdf outputPage-%%d.pdf\n", arg0);
	return -1;
}

int main( int argc, char* argv[] )
{
	int opt;
	int startPage = 1;
	int lastPage = 1;
	while ((opt = getopt(argc,argv,"f:l:h")) != -1)
	{
		switch (opt)
		{
		case 'f':
			try {
				startPage = atoi(optarg);
			}catch(...){ return usage(argv[0]); }
			if (startPage < 1)
				return usage(argv[0]);
			break;
		case 'l':
			try {
				lastPage = atoi(optarg);
			}catch(...){ return usage(argv[0]); }
			break;
		case 'h':
			return usage(argv[0]);
		}
	}	
	if (optind > argc - 2)
		return usage(argv[0]);
	std::string inputFile = argv[optind];
	std::string outputPattern = argv[optind+1];
	auto idx = outputPattern.find("%d");
	if (idx == std::string::npos)
		return usage(argv[0]);
	outputPattern.erase(idx, 2);
	std::vector<std::string> outputFiles;
	for (int pageNo = startPage; pageNo <= lastPage; ++pageNo)
	{
		std::string outputFile = outputPattern;
		outputFile.insert(idx, std::to_string(pageNo));
		outputFiles.push_back(std::move(outputFile));
	}
	std::string error;
	if( !PdfOps::ExtractPages(inputFile, startPage-1, outputFiles, error))
	{
		fprintf(stderr,"%s\n", error.c_str());
		return -1;
	}
	return 0;
}
