MD   = $(wildcard [a-zA-Z]*.md) # do not publish _* files
PDF  = $(MD:.md=.pdf)
HTML = $(MD:.md=.html)
DOCX = $(MD:.md=.docx)

HFLAGS = -s -t html5
HFLAGS += -M classoption=fleqn
HFLAGS += --css=math.css
HFLAGS += --katex
HFLAGS += --toc
HFLAGS += -H HEADER.md

%.html: %.md $(CSS)
	pandoc $(HFLAGS) $< -o $@

%.pdf: %.md 
	pandoc $< -o $@
