#benchmark
( time srun -N1 -n1 -c1 --nodelist=node2 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace2/benchmark1/req1.vc3 )  &> b1_plcverif_CBMC_req1.log &
( time srun -N1 -n1 -c1 --nodelist=node2 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace2/benchmark1/req2.vc3 )  &> b1_plcverif_CBMC_req2.log &
( time srun -N1 -n1 -c1 --nodelist=node2 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace2/benchmark1/req3.vc3 )  &> b1_plcverif_CBMC_req3.log &

#benchmark2
( time srun -N1 -n1 -c1 --nodelist=node2 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace2/benchmark2/req1.vc3 )  &> b2_plcverif_CBMC_req1.log &
( time srun -N1 -n1 -c1 --nodelist=node5 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace2/benchmark2/req2.vc3 )  &> b2_plcverif_CBMC_req2.log &
( time srun -N1 -n1 -c1 --nodelist=node5 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace2/benchmark2/req3.vc3 )  &> b2_plcverif_CBMC_req3.log &

#benchmark3
( time srun -N1 -n1 -c1 --nodelist=node5 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace2/benchmark3/req1.vc3 )  &> b3_plcverif_CBMC_req1.log &
( time srun -N1 -n1 -c1 --nodelist=node5 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace2/benchmark3/req2.vc3 )  &> b3_plcverif_CBMC_req2.log &
( time srun -N1 -n1 -c1 --nodelist=node5 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace2/benchmark3/req3.vc3 )  &> b3_plcverif_CBMC_req3.log &

#benchmark4
( time srun -N1 -n1 -c1 --nodelist=node5 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace2/benchmark4/req1.vc3 )  &> b4_plcverif_CBMC_req1.log &
( time srun -N1 -n1 -c1 --nodelist=node5 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace2/benchmark4/req2.vc3 )  &> b4_plcverif_CBMC_req2.log &
( time srun -N1 -n1 -c1 --nodelist=node5 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace2/benchmark4/req3.vc3 )  &> b4_plcverif_CBMC_req3.log &
( time srun -N1 -n1 -c1 --nodelist=node5 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace2/benchmark4/req4.vc3 )  &> b4_plcverif_CBMC_req4.log &
( time srun -N1 -n1 -c1 --nodelist=node5 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace2/benchmark4/req5.vc3 )  &> b4_plcverif_CBMC_req5.log &

#benchmark5
( time srun -N1 -n1 -c1 --nodelist=node5 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace2/benchmark5/req1.vc3 )  &> b5_plcverif_CBMC_req1.log &
( time srun -N1 -n1 -c1 --nodelist=node5 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace2/benchmark5/req2.vc3 )  &> b5_plcverif_CBMC_req2.log &

#benchmark6
( time srun -N1 -n1 -c1 --nodelist=node3 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace2/benchmark6/req1.vc3 )  &> b6_plcverif_CBMC_req1.log &

#benchmark7
( time srun -N1 -n1 -c1 --nodelist=node3 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace2/benchmark7/req1.vc3 )  &> b7_plcverif_CBMC_req1.log &
( time srun -N1 -n1 -c1 --nodelist=node3 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace2/benchmark7/req2.vc3 )  &> b7_plcverif_CBMC_req2.log &
( time srun -N1 -n1 -c1 --nodelist=node3 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace2/benchmark7/req3.vc3 )  &> b7_plcverif_CBMC_req3.log &

#benchmark8
( time srun -N1 -n1 -c1 --nodelist=node3 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace2/benchmark8/req1.vc3 )  &> b8_plcverif_CBMC_req1.log &
( time srun -N1 -n1 -c1 --nodelist=node3 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace2/benchmark8/req2.vc3 )  &> b8_plcverif_CBMC_req2.log &
( time srun -N1 -n1 -c1 --nodelist=node3 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace2/benchmark8/req3.vc3 )  &> b8_plcverif_CBMC_req3.log &

#benchmark9
( time srun -N1 -n1 -c1 --nodelist=node5 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace2/benchmark9/req1.vc3 )  &> b9_plcverif_CBMC_req1.log &
( time srun -N1 -n1 -c1 --nodelist=node5 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace2/benchmark9/req2.vc3 )  &> b9_plcverif_CBMC_req2.log &
( time srun -N1 -n1 -c1 --nodelist=node5 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace2/benchmark9/req3.vc3 )  &> b9_plcverif_CBMC_req3.log &

#benchmark10
( time srun -N1 -n1 -c1 --nodelist=node5 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace2/benchmark10/req1.vc3 )  &> b10_plcverif_CBMC_req1.log &
( time srun -N1 -n1 -c1 --nodelist=node5 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace2/benchmark10/req2.vc3 )  &> b10_plcverif_CBMC_req2.log &
( time srun -N1 -n1 -c1 --nodelist=node5 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace2/benchmark10/req3.vc3 )  &> b10_plcverif_CBMC_req3.log &
( time srun -N1 -n1 -c1 --nodelist=node5 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace2/benchmark10/req4.vc3 )  &> b10_plcverif_CBMC_req4.log &
( time srun -N1 -n1 -c1 --nodelist=node5 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace2/benchmark10/req5.vc3 )  &> b10_plcverif_CBMC_req5.log &

#benchmark11
( time srun -N1 -n1 -c1 --nodelist=node5 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace2/benchmark11/req1.vc3 )  &> b11_plcverif_CBMC_req1.log &
( time srun -N1 -n1 -c1 --nodelist=node5 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace2/benchmark11/req2.vc3 )  &> b11_plcverif_CBMC_req2.log &

#benchmark12
( time srun -N1 -n1 -c1 --nodelist=node5 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace2/benchmark12/req1.vc3 )  &> b12_plcverif_CBMC_req1.log &

#benchmark13
( time srun -N1 -n1 -c1 --nodelist=node5 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace2/benchmark13/req1.vc3 )  &> b13_plcverif_CBMC_req1.log &
( time srun -N1 -n1 -c1 --nodelist=node5 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace2/benchmark13/req2.vc3 )  &> b13_plcverif_CBMC_req2.log &
( time srun -N1 -n1 -c1 --nodelist=node5 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace2/benchmark13/req3.vc3 )  &> b13_plcverif_CBMC_req3.log &

#benchmark14
( time srun -N1 -n1 -c1 --nodelist=node5 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace2/benchmark14/req1.vc3 )  &> b14_plcverif_CBMC_req1.log &
( time srun -N1 -n1 -c1 --nodelist=node5 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace2/benchmark14/req2.vc3 )  &> b14_plcverif_CBMC_req2.log &

#benchmark15
( time srun -N1 -n1 -c1 --nodelist=node5 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace2/benchmark15/req1.vc3 )  &> b15_plcverif_CBMC_req1.log &

#benchmark16
( time srun -N1 -n1 -c1 --nodelist=node5 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace2/benchmark16/req1.vc3 )  &> b16_plcverif_CBMC_req1.log &
( time srun -N1 -n1 -c1 --nodelist=node4 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace2/benchmark16/req2.vc3 )  &> b16_plcverif_CBMC_req2.log &
( time srun -N1 -n1 -c1 --nodelist=node4 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace2/benchmark16/req3.vc3 )  &> b16_plcverif_CBMC_req3.log &

#benchmark17
( time srun -N1 -n1 -c1 --nodelist=node4 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace2/benchmark17/req1.vc3 )  &> b17_plcverif_CBMC_req1.log &

#benchmark18
( time srun -N1 -n1 -c1 --nodelist=node4 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace2/benchmark18/req1.vc3 )  &> b18_plcverif_CBMC_req1.log &

#caseStudy
( time srun -N1 -n1 -c1 --nodelist=node4 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace2/caseStudy/req1.vc3 )  &> caseStudy_plcverif_CBMC_req1.log &
( time srun -N1 -n1 -c1 --nodelist=node4 ./benchmark/plcverif/cmd/plcverif-cli benchmark/plcverif/cmd/workspace2/caseStudy/req2.vc3 )  &> caseStudy_plcverif_CBMC_req2.log &