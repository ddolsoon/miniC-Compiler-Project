TARGET = miniC++
OBJECT = lex.yy.c parser.tab.c parser.tab.h

$(TARGET) : $(OBJECT)
	gcc -o  $@ $^ ast.c CFG.c timer.c -lfl

parser.tab.c parser.tab.h : parser.y
	bison -d $^

lex.yy.c : scanner.l parser.tab.h
	flex $<
	
clean:
	rm $(OBJECTS) $(TARGET)
