#benchmark
( time srun -N1 -n1 -c1 --nodelist=node3 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace/benchmark1/req1.vc3 )  &> b1_plcverif_req1.log &
( time srun -N1 -n1 -c1 --nodelist=node3 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace/benchmark1/req2.vc3 )  &> b1_plcverif_req2.log &
( time srun -N1 -n1 -c1 --nodelist=node3 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace/benchmark1/req3.vc3 )  &> b1_plcverif_req3.log &

#benchmark2
( time srun -N1 -n1 -c1 --nodelist=node3 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace/benchmark2/req1.vc3 )  &> b2_plcverif_req1.log &
( time srun -N1 -n1 -c1 --nodelist=node3 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace/benchmark2/req2.vc3 )  &> b2_plcverif_req2.log &
( time srun -N1 -n1 -c1 --nodelist=node3 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace/benchmark2/req3.vc3 )  &> b2_plcverif_req3.log &

#benchmark3
( time srun -N1 -n1 -c1 --nodelist=node3 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace/benchmark3/req1.vc3 )  &> b3_plcverif_req1.log &
( time srun -N1 -n1 -c1 --nodelist=node3 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace/benchmark3/req2.vc3 )  &> b3_plcverif_req2.log &
( time srun -N1 -n1 -c1 --nodelist=node3 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace/benchmark3/req3.vc3 )  &> b3_plcverif_req3.log &

#benchmark4
( time srun -N1 -n1 -c1 --nodelist=node3 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace/benchmark4/req1.vc3 )  &> b4_plcverif_req1.log &
( time srun -N1 -n1 -c1 --nodelist=node3 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace/benchmark4/req2.vc3 )  &> b4_plcverif_req2.log &
( time srun -N1 -n1 -c1 --nodelist=node3 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace/benchmark4/req3.vc3 )  &> b4_plcverif_req3.log &
( time srun -N1 -n1 -c1 --nodelist=node3 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace/benchmark4/req4.vc3 )  &> b4_plcverif_req4.log &
( time srun -N1 -n1 -c1 --nodelist=node3 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace/benchmark4/req5.vc3 )  &> b4_plcverif_req5.log &

#benchmark5
( time srun -N1 -n1 -c1 --nodelist=node3 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace/benchmark5/req1.vc3 )  &> b5_plcverif_req1.log &
( time srun -N1 -n1 -c1 --nodelist=node3 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace/benchmark5/req2.vc3 )  &> b5_plcverif_req2.log &

#benchmark6
( time srun -N1 -n1 -c1 --nodelist=node3 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace/benchmark6/req1.vc3 )  &> b6_plcverif_req1.log &

#benchmark7
( time srun -N1 -n1 -c1 --nodelist=node3 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace/benchmark7/req1.vc3 )  &> b7_plcverif_req1.log &
( time srun -N1 -n1 -c1 --nodelist=node3 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace/benchmark7/req2.vc3 )  &> b7_plcverif_req2.log &
( time srun -N1 -n1 -c1 --nodelist=node3 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace/benchmark7/req3.vc3 )  &> b7_plcverif_req3.log &

#benchmark8
( time srun -N1 -n1 -c1 --nodelist=node3 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace/benchmark8/req1.vc3 )  &> b8_plcverif_req1.log &
( time srun -N1 -n1 -c1 --nodelist=node3 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace/benchmark8/req2.vc3 )  &> b8_plcverif_req2.log &
( time srun -N1 -n1 -c1 --nodelist=node3 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace/benchmark8/req3.vc3 )  &> b8_plcverif_req3.log &

#benchmark9
( time srun -N1 -n1 -c1 --nodelist=node4 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace/benchmark9/req1.vc3 )  &> b9_plcverif_req1.log &
( time srun -N1 -n1 -c1 --nodelist=node4 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace/benchmark9/req2.vc3 )  &> b9_plcverif_req2.log &
( time srun -N1 -n1 -c1 --nodelist=node4 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace/benchmark9/req3.vc3 )  &> b9_plcverif_req3.log &

#benchmark10
( time srun -N1 -n1 -c1 --nodelist=node4 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace/benchmark10/req1.vc3 )  &> b10_plcverif_req1.log &
( time srun -N1 -n1 -c1 --nodelist=node4 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace/benchmark10/req2.vc3 )  &> b10_plcverif_req2.log &
( time srun -N1 -n1 -c1 --nodelist=node4 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace/benchmark10/req3.vc3 )  &> b10_plcverif_req3.log &
( time srun -N1 -n1 -c1 --nodelist=node4 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace/benchmark10/req4.vc3 )  &> b10_plcverif_req4.log &
( time srun -N1 -n1 -c1 --nodelist=node4 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace/benchmark10/req5.vc3 )  &> b10_plcverif_req5.log &

#benchmark11
( time srun -N1 -n1 -c1 --nodelist=node4 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace/benchmark11/req1.vc3 )  &> b11_plcverif_req1.log &
( time srun -N1 -n1 -c1 --nodelist=node4 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace/benchmark11/req2.vc3 )  &> b11_plcverif_req2.log &

#benchmark12
( time srun -N1 -n1 -c1 --nodelist=node4 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace/benchmark12/req1.vc3 )  &> b12_plcverif_req1.log &

#benchmark13
( time srun -N1 -n1 -c1 --nodelist=node4 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace/benchmark13/req1.vc3 )  &> b13_plcverif_req1.log &
( time srun -N1 -n1 -c1 --nodelist=node4 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace/benchmark13/req2.vc3 )  &> b13_plcverif_req2.log &
( time srun -N1 -n1 -c1 --nodelist=node4 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace/benchmark13/req3.vc3 )  &> b13_plcverif_req3.log &

#benchmark14
( time srun -N1 -n1 -c1 --nodelist=node4 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace/benchmark14/req1.vc3 )  &> b14_plcverif_req1.log &
( time srun -N1 -n1 -c1 --nodelist=node4 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace/benchmark14/req2.vc3 )  &> b14_plcverif_req2.log &

#benchmark15
( time srun -N1 -n1 -c1 --nodelist=node4 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace/benchmark15/req1.vc3 )  &> b15_plcverif_req1.log &

#benchmark16
( time srun -N1 -n1 -c1 --nodelist=node4 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace/benchmark16/req1.vc3 )  &> b16_plcverif_req1.log &
( time srun -N1 -n1 -c1 --nodelist=node4 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace/benchmark16/req2.vc3 )  &> b16_plcverif_req2.log &
( time srun -N1 -n1 -c1 --nodelist=node4 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace/benchmark16/req3.vc3 )  &> b16_plcverif_req3.log &

#benchmark17
( time srun -N1 -n1 -c1 --nodelist=node4 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace/benchmark17/req1.vc3 )  &> b17_plcverif_req1.log &

#benchmark18
( time srun -N1 -n1 -c1 --nodelist=node4 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace/benchmark18/req1.vc3 )  &> b18_plcverif_req1.log &

#caseStudy
( time srun -N1 -n1 -c1 --nodelist=node4 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace/caseStudy/req1.vc3 )  &> caseStudy_plcverif_req1.log &
( time srun -N1 -n1 -c1 --nodelist=node4 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace/caseStudy/req2.vc3 )  &> caseStudy_plcverif_req2.log &