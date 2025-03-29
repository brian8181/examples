# wx-config to use, may be overridden on make command line.
WX_CONFIG := wx-config

WX_CXXFLAGS := $(shell $(WX_CONFIG) --cxxflags)
WX_LIBS := $(shell $(WX_CONFIG) --libs)

OBJECTS := hello.o bye.o

hello: $(OBJECTS)
    $(CXX) -o $@ $(OBJECTS) $(LDFLAGS) $(WX_LIBS) -I/usr/local/include/cppunit/ $(LIBS)

$(OBJECTS): %.o: %.cpp
    $(CXX) -c -o $@ $(WX_CXXFLAGS) $(CXXFLAGS) $<