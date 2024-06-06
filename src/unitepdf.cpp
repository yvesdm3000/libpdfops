#include <PdfOps.h>

#include <stdio.h>

int main( int argc, char* argv[] )
{
  std::vector<std::string> inputFiles;
  for ( int i=1; i < argc-1; ++i)
  {
    inputFiles.push_back( argv[i] );
  }

  if (!PdfOps::UniteFiles( inputFiles, argv[argc-1] ))
		return -1;
	return 0;
}
