#pragma once

#include <vector>
#include <string>

namespace PdfOps {
	int PageCount( const std::string& inputFile );
  bool UniteFiles( const std::vector<std::string>& inputFiles, const std::string& outputFile );
	bool ExtractPages( const std::string& inputFile, int start, const std::vector<std::string>& outputFiles, std::string& error );
};

