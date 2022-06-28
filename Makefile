CXX := g++
INSTALL_DIST := /usr/local/bin

will:
	$(CXX) main.cpp -o will
WILL: will
install: will
	mv will $(INSTALL_DIST)