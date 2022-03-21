g++ main.cpp prokudin.cpp mstwpdf/mstwpdf.cc `root-config --cflags --glibs`
./a.out

#root -l -b<<EOF
#.L cross_SIDIS.C
#cross_SIDIS()
#.q
#EOF
