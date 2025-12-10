#コンパイラ
CC = g++
#コンパイルオプション
CFLAGS = -g -Wall
#実行ファイル名
TARGET = crypto
#コンパイル対象ソースコード（複数選択時 +=）
SRCS   = main.cpp
SRCS   += GMO.cpp
SRCS   += CoinCheck.cpp
SRCS   += bitbank.cpp
SRCS   += bitFlyer.cpp
#オブジェクトファイル名
OBJS   = $(SRCS:.cpp=.o)
#パス
INCDIR = -I../inc
#パス
LIBDIR = 
#追加するライブラリファイル
LIBS   = -lcurl
#ターゲットファイル生成
$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(LIBDIR) $(LIBS)
#オブジェクトファイル生成
%.o: %.cpp
	$(CC) $(CFLAGS) $(INCDIR) -c $< -o $@
#make allでmake cleanとmakeを同時に実施
all: $(TARGET)
#.oファイル、実行ファイル、.dファイルを削除
clean:
	-rm -f $(OBJS) $(TARGET) 