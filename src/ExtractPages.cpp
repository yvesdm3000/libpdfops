#include <PdfOps.h>

#include <PDFDoc.h>
#include <ErrorCodes.h>
#include <GlobalParams.h>

std::string g_error;
	void error_cb(ErrorCategory, Goffset, const char* msg) {
		g_error = msg;
	}

bool PdfOps::ExtractPages( const std::string& inputFile, int firstPage, const std::vector<std::string>& outputFiles, std::string& error )
{
	GlobalParamsIniter gp( error_cb );

	std::unique_ptr<PDFDoc> doc = std::make_unique<PDFDoc>(new GooString(inputFile.c_str()), nullptr, nullptr, nullptr);

	if (!doc->isOk()) {
		error = "Could not extract page(s) from damaged file ('"+ inputFile+"')";
		return false;
	}

	int lastPage = outputFiles.size()-1;
	if (lastPage >= doc->getNumPages())
	{
		error = "Not enough pages in the source document";
		return false;
	}

	if (lastPage < firstPage) {
		error = "Wrong page range given: the first page ("+std::to_string(firstPage)+") can not be after the last page ("+std::to_string(lastPage)+")";
		return false;
	}

	for (int pageNo = firstPage; pageNo <= lastPage; pageNo++) {
		GooString *gpageName = new GooString(outputFiles[pageNo]);
		std::unique_ptr<PDFDoc> pagedoc = std::make_unique<PDFDoc>(new GooString(inputFile.c_str()), nullptr, nullptr, nullptr);
		int errCode = pagedoc->savePageAs(gpageName, pageNo+1);
		if (errCode != errNone) {
			error = g_error;
			return false;
		}
	}
	return true;
}
