## Fuzzing Test Cases 
Build and install afl-2.52b:
```
$ bash build_afl.sh
```
### ASan Model
1. set ASan to compile fuzzing targets:
```
$ bash set_ASan.sh
```
2. Build fuzzing target softwares:\
For each program, we provide an `auto_build_ASan.sh` script under source code file. Here is an example to build `binutils-2.32`:
```
$ cd binutils-2.32
$ bash auto_build_ASan.sh
```
3. Start fuzzing, Weee!\
For each software, we have prepared the fuzzing script in `fuzzing_script`. Here is an example to fuzz program `nm-new`.
```
./afl-2.52b/afl-fuzz -S nm_afl_asan -i ./afl-2.52b/testcases/others/elf/ -o ./eval/nm -m none -- ./binutils-2.32/ASan/binutils/nm-new @@
```
4. All fuzzing results will be under `eval` folder.
### ASan--FuZZan Model
1. set ASan-- to compile fuzzing targets:
```
$ bash set_ASan--.sh
```
2. Build libshrink to shrink address space:
```
cd libshrink
./build.sh
```
3. Build fuzzing target softwares:\
For each program, we have prepared an `auto_build_ASan--.sh` script under the source code file. Here is an example to build `binutils-2.32`:
```
$ cd binutils-2.32
$ bash auto_build_ASan--.sh
```
4. Reduce the address space for each fuzzing target:
```
$ cd libshrink
$ bash auto_wrap.sh
```
5. Start fuzzing, Weee!\
For each software, we have prepared the fuzzing script in `fuzzing_script`. Here is an example to fuzz program `nm-new`.
```
./afl-2.52b/afl-fuzz -S nm_afl -i ./afl-2.52b/testcases/others/elf/ -o ./eval/nm -m none -- ./libshrink/prelink-nm/nm-new @@
```
6. All fuzzing results will be under `eval` folder.

### ASan-- Model
1. set ASan-- to compile fuzzing targets:
```
$ bash set_ASan--.sh
```
2. Build fuzzing target softwares:\
For each program, we have prepared an `auto_build_ASan--.sh` script under the source code file. Here is an example to build `binutils-2.32`:
```
$ cd binutils-2.32
$ bash auto_build_ASan--.sh
```
3. Start fuzzing, Weee!\
For each software, we have prepared the fuzzing script in `fuzzing_script`. Here is an example to fuzz program `nm-new`.
```
./afl-2.52b/afl-fuzz -S nm_afl -i ./afl-2.52b/testcases/others/elf/ -o ./eval/nm -m none -- ./binutils-2.32/ASan_Srk/binutils/nm-new @@
```
4. All fuzzing results will be under `eval` folder.
