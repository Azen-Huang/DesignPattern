# $@: 目标文件, $^: 所有依赖文件, $<: 第一个依赖文件
# 语法规则:
# 	targets: prerequisites
# 		command
dest_dir = build
src_dir = src
obj_dir = $(dest_dir)/objects
bin_dir = $(dest_dir)/bin

CC = g++
RESULT = main
CFLAGS = -Wall -O3 -std=c++17
CFILES = main.cpp
ofiles = $(CFILES:%.cpp=$(obj_dir)/%.o)

program = $(bin_dir)/$(RESULT)
$(program): $(ofiles)

$(bin_dir)/%:
	@echo ">>> Linking" $@ "<<<"
	@if [ ! -d $(bin_dir) ]; then mkdir -p $(bin_dir); fi;
	$(CC) -o $@ $^
	ln -sf $@ $(notdir $@)

$(obj_dir)/%.o: $(src_dir)/%.cpp
	@echo ">>> Compiling" $< "<<<"
	@if [ ! -d $(obj_dir) ]; then mkdir -p $(obj_dir); fi;
	$(CC) $(CFLAGS) -c $< -o $@

$(obj_dir)/%.o: $(src_dir)/*/%.cpp
	@echo ">>> Compiling" $< "<<<"
	@if [ ! -d $(obj_dir) ]; then mkdir -p $(obj_dir); fi;
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf $(dest_dir)
	rm -f $(RESULT)