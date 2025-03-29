#include <mpegfile.h>
#include <attachedpictureframe.h>
#include <id3v2tag.h>
#include <mp4file.h>
#include <mp4tag.h>
#include <mp4coverart.h>

#include <iostream>

class ImageFile : public TagLib::File
{
public:
	ImageFile(const char *file) : TagLib::File(file)
	{
	}

	TagLib::ByteVector data()
	{
		return readBlock(length());
	}

private:
	virtual TagLib::Tag *tag() const { return 0; }
	virtual TagLib::AudioProperties *audioProperties() const { return 0; }
	virtual bool save() { return false; }
};

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		std::cout << "Usage: setcover <mp3|m4a> cover.jpg" << std::endl;
		return 1;
	}

	TagLib::String fileName = argv[1];
	TagLib::String fileType = fileName.substr(fileName.size() - 3).upper();

	ImageFile imageFile(argv[2]);

	if (fileType == "M4A")
	{
		// read the image file
		TagLib::MP4::CoverArt coverArt((TagLib::MP4::CoverArt::Format)0x0D, imageFile.data());
		// read the mp4 file
		TagLib::MP4::File audioFile(argv[1]);
		// get the tag ptr
		TagLib::MP4::Tag *tag = audioFile.tag();
		// get the items map
		TagLib::MP4::ItemListMap itemsListMap = tag->itemListMap();
		// create cover art list
		TagLib::MP4::CoverArtList coverArtList;
		// append instance
		coverArtList.append(coverArt);
		// convert to item
		TagLib::MP4::Item coverItem(coverArtList);
		// add item to map
		itemsListMap.insert("covr", coverItem);
		tag->save();
		// audioFile.save();
	}
	else if (fileType == "MP3")
	{
		TagLib::MPEG::File audioFile(argv[1]);
		TagLib::ID3v2::Tag *tag = audioFile.ID3v2Tag(true);
		TagLib::ID3v2::AttachedPictureFrame *frame = new TagLib::ID3v2::AttachedPictureFrame;

		frame->setMimeType("image/jpeg");
		frame->setPicture(imageFile.data());

		tag->addFrame(frame);
		audioFile.save();
	}
	else
	{
		std::cout << fileType << " is unsupported." << std::endl;
	}
}