# Edit it if you are not ok with /usr/local/bin and /usr/local/share/man/man1
INSTALL_DIST =
CXX ?= g++

will:
	$(CXX) main.cpp -o will
WILL: will

clean:
	rm will

install: will
	install -d $(INSTALL_DIST)/usr/local/bin $(INSTALL_DIST)/usr/local/share/man/man1
	install -m 644 will.1 $(INSTALL_DIST)/usr/local/share/man/man1
	install will $(INSTALL_DIST)/usr/local/bin
	make clean