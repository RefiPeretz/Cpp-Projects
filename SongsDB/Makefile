cc = g++
cppflag = -std=c++11 -Wextra -Wall -g
OBJECTS = RankableSong.o RankableLyricSong.o RankableInstrumentSong.o Rankable.o Song.o \
SongDataBase.o SongFilters.o SongFactory.o MIR.o ParameterFactory.o Parameters.o
CPP_FILES = MIR.cpp RankableSong.cpp RankableLyricSong.cpp RankableInstrumentSong.cpp \
 SongFilters.cpp Song.cpp SongFactory.cpp Parameters.cpp Rankable.cpp SongDataBase.cpp \
  ParameterFactory.cpp
HEAD_FILES = RankableSong.h Song.h RankableInstrumentSong.h Rankable.h Parameters.h \
 ParameterFactory.h SongDataBase.h SongFactory.h RankableLyricSong.h SongFilters.h

all: MIR

MIR: $(OBJECTS)

	$(cc) $(cppflag) $(OBJECTS) -o MIR

MIR.o: MIR.cpp SongDataBase.h
	$(cc) -c $(cppflag) MIR.cpp

SongFilters.o: Parameters.h SongFilters.h SongFilters.cpp
	$(cc) -c $(cppflag) SongFilters.cpp

Rankable.o: Rankable.h Rankable.cpp
	$(cc) -c $(cppflag) Rankable.cpp

Song.o: Song.h Song.cpp
	$(cc) -c $(cppflag) Song.cpp

RankableSong.o:  RankableSong.cpp RankableSong.h Song.h Rankable.h SongFilters.h
	$(cc) -c $(cppflag) RankableSong.cpp

RankableLyricSong.o: RankableLyricSong.cpp RankableLyricSong.h
	$(cc) -c $(cppflag) RankableLyricSong.cpp

RankableInstrumentSong.o: RankableInstrumentSong.h RankableInstrumentSong.cpp
	$(cc) -c $(cppflag) RankableInstrumentSong.cpp

SongDataBase.o: SongDataBase.cpp SongDataBase.h
	$(cc) -c $(cppflag) SongDataBase.cpp

SongFactory.o: SongFactory.h SongFactory.cpp
	$(cc) -c $(cppflag) SongFactory.cpp

ParameterFactory.o: ParameterFactory.h ParameterFactory.cpp
	$(cc) -c $(cppflag) ParameterFactory.cpp

Parameters.o: Parameters.h Parameters.cpp
	$(cc) -c $(cppflag) Parameters.cpp







tar:
	tar cvf ex2.tar $(CPP_FILES) $(HEAD_FILES) extension.pdf README Makefile

clean:
	rm -f *.o MIR ex2.tar

.PHONY: all tar clean
