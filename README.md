URIComponentsDisplay
====================

GUI application which breaks URI down into its individual components as defined in RFC 3986 and displays those components to the user.

====================
Enviroment:
	os: Ubuntu 12.10 x64
	g++: 4.7.2
	boost: 1.50.0
	qt: 5.0.2
	QtCreator 2.7.0

	Program is not platform dependent. Is should work in all environments supporting boost, qt and QTCreator in mentioned versions. Qt may require  external software for compilation. For me it was libgl1-mesa-dev. Used g++ version is a default one for my version of Ubuntu.

====================
Design remarks:

	There are two projects. Test(UnitTest) and Gui application(URILinkParser). Gui project is located inside test one. You run it separately.
