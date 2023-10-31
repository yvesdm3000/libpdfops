#pragma once

#include <vector>
#include <string>

namespace PdfOps {
  bool UniteFiles( const std::vector<std::string>& inputFiles, const std::string& outputFile );
};

