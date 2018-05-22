#!/bin/bash
mkdir doc
echo "Running Tests ..."
./bin/Test_Decreasing_Sample > doc/Test_Decreasing_Sample.out
./bin/Test_Flat_Sample > doc/Test_Flat_Sample.out
./bin/Test_Increasing_Sample > doc/Test_Increasing_Sample.out
./bin/Test_Init > doc/Test_Init.out
./bin/Test_Middle_Around_Flat > doc/Test_Middle_Around_Flat.out
./bin/Test_Random_Sample > doc/Test_Random_Sample.out

echo "Done. See output in doc folder."

