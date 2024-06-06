#include <PdfOps.h>

#include <PDFDoc.h>
#include <GlobalParams.h>

int PdfOps::PageCount( const std::string& inputFile )
{
	std::unique_ptr<PDFDoc> doc = std::make_unique<PDFDoc>(new GooString(inputFile.c_str()), nullptr, nullptr, nullptr);
	if (!doc->isOk()) {
		return 0;
	}
	return doc->getNumPages();
}
