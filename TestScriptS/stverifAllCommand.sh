#caseStudy
: <<'END'
( time srun -N1 -n1 -c1 --nodelist=node1 --time 02:00:00 ./../stverif.sh ../benchmark/straton/caseStudy ../benchmark/stverif/caseStudy/req1_INF.req )  &> caseStudy_req1_INF.log & 
( time srun -N1 -n1 -c1 --nodelist=node1 --time 02:00:00 ./../stverif.sh ../benchmark/straton/caseStudy ../benchmark/stverif/caseStudy/req2_INF.req )  &> caseStudy_req2_INF.log &
END

#benchmark1
( time srun -N1 -n1 -c1 --nodelist=node1 --time 02:00:00 ./../stverif.sh ../benchmark/straton/benchmark1/benchmark1 ../benchmark/stverif/benchmark1/req1_INF.req  )  &> b1_req1_INF.log &
( time srun -N1 -n1 -c1 --nodelist=node3 --time 02:00:00 ./../stverif.sh ../benchmark/straton/benchmark1/benchmark1 ../benchmark/stverif/benchmark1/req2_INF.req  )  &> b1_req2_INF.log &
( time srun -N1 -n1 -c1 --nodelist=node3 --time 02:00:00 ./../stverif.sh ../benchmark/straton/benchmark1/benchmark1 ../benchmark/stverif/benchmark1/req3_INF.req  )  &> b1_req3_INF.log &

#benchmark2
( time srun -N1 -n1 -c1 --nodelist=node3 --time 02:00:00 ./../stverif.sh ../benchmark/straton/benchmark2/benchmark2 ../benchmark/stverif/benchmark2/req1_INF.req  )  &> b2_req1_INF.log &
( time srun -N1 -n1 -c1 --nodelist=node3 --time 02:00:00 ./../stverif.sh ../benchmark/straton/benchmark2/benchmark2 ../benchmark/stverif/benchmark2/req2_INF.req  )  &> b2_req2_INF.log &
( time srun -N1 -n1 -c1 --nodelist=node3 --time 02:00:00 ./../stverif.sh ../benchmark/straton/benchmark2/benchmark2 ../benchmark/stverif/benchmark2/req3_INF.req  )  &> b2_req3_INF.log &

#benchmark3
( time srun -N1 -n1 -c1 --nodelist=node3 --time 02:00:00 ./../stverif.sh ../benchmark/straton/benchmark3/benchmark3 ../benchmark/stverif/benchmark3/req1_INF.req  )  &> b3_req1_INF.log &
( time srun -N1 -n1 -c1 --nodelist=node3 --time 02:00:00 ./../stverif.sh ../benchmark/straton/benchmark3/benchmark3 ../benchmark/stverif/benchmark3/req2_INF.req  )  &> b3_req2_INF.log &
( time srun -N1 -n1 -c1 --nodelist=node3 --time 02:00:00 ./../stverif.sh ../benchmark/straton/benchmark3/benchmark3 ../benchmark/stverif/benchmark3/req3_INF.req  )  &> b3_req3_INF.log &

#benchmark4
( time srun -N1 -n1 -c1 --nodelist=node3 --time 02:00:00 ./../stverif.sh ../benchmark/straton/benchmark4/benchmark4 ../benchmark/stverif/benchmark4/req1_INF.req  )  &> b4_req1_INF.log &
( time srun -N1 -n1 -c1 --nodelist=node3 --time 02:00:00 ./../stverif.sh ../benchmark/straton/benchmark4/benchmark4 ../benchmark/stverif/benchmark4/req2_INF.req  )  &> b4_req2_INF.log &
( time srun -N1 -n1 -c1 --nodelist=node3 --time 02:00:00 ./../stverif.sh ../benchmark/straton/benchmark4/benchmark4 ../benchmark/stverif/benchmark4/req3_INF.req  )  &> b4_req3_INF.log &
( time srun -N1 -n1 -c1 --nodelist=node3 --time 02:00:00 ./../stverif.sh ../benchmark/straton/benchmark4/benchmark4 ../benchmark/stverif/benchmark4/req4_INF.req  )  &> b4_req4_INF.log &
( time srun -N1 -n1 -c1 --nodelist=node3 --time 02:00:00 ./../stverif.sh ../benchmark/straton/benchmark4/benchmark4 ../benchmark/stverif/benchmark4/req5_INF.req  )  &> b4_req5_INF.log &

#benchmark5
( time srun -N1 -n1 -c1 --nodelist=node3 --time 02:00:00 ./../stverif.sh ../benchmark/straton/benchmark5/benchmark5 ../benchmark/stverif/benchmark5/req1_INF.req  )  &> b5_req1_INF.log &
( time srun -N1 -n1 -c1 --nodelist=node3 --time 02:00:00 ./../stverif.sh ../benchmark/straton/benchmark5/benchmark5 ../benchmark/stverif/benchmark5/req2_INF.req  )  &> b5_req2_INF.log &

#benchmark6
( time srun -N1 -n1 -c1 --nodelist=node3 --time 02:00:00 ./../stverif.sh ../benchmark/straton/benchmark6/benchmark6 ../benchmark/stverif/benchmark6/req1_INF.req  )  &> b6_req1_INF.log &

#benchmark7
( time srun -N1 -n1 -c1 --nodelist=node3 --time 02:00:00 ./../stverif.sh ../benchmark/straton/benchmark7/benchmark7 ../benchmark/stverif/benchmark7/req1_INF.req  )  &> b7_req1_INF.log &
( time srun -N1 -n1 -c1 --nodelist=node3 --time 02:00:00 ./../stverif.sh ../benchmark/straton/benchmark7/benchmark7 ../benchmark/stverif/benchmark7/req2_INF.req  )  &> b7_req2_INF.log &
( time srun -N1 -n1 -c1 --nodelist=node3 --time 02:00:00 ./../stverif.sh ../benchmark/straton/benchmark7/benchmark7 ../benchmark/stverif/benchmark7/req3_INF.req  )  &> b7_req3_INF.log &

#benchmark8
( time srun -N1 -n1 -c1 --nodelist=node3 --time 02:00:00 ./../stverif.sh ../benchmark/straton/benchmark8/benchmark8 ../benchmark/stverif/benchmark8/req1_INF.req  )  &> b8_req1_INF.log &
( time srun -N1 -n1 -c1 --nodelist=node3 --time 02:00:00 ./../stverif.sh ../benchmark/straton/benchmark8/benchmark8 ../benchmark/stverif/benchmark8/req2_INF.req  )  &> b8_req2_INF.log &
( time srun -N1 -n1 -c1 --nodelist=node3 --time 02:00:00 ./../stverif.sh ../benchmark/straton/benchmark8/benchmark8 ../benchmark/stverif/benchmark8/req3_INF.req  )  &> b8_req3_INF.log &

#benchmark9
( time srun -N1 -n1 -c1 --nodelist=node3 --time 02:00:00 ./../stverif.sh ../benchmark/straton/benchmark9/benchmark9 ../benchmark/stverif/benchmark9/req1_INF.req  )  &> b9_req1_INF.log &
( time srun -N1 -n1 -c1 --nodelist=node3 --time 02:00:00 ./../stverif.sh ../benchmark/straton/benchmark9/benchmark9 ../benchmark/stverif/benchmark9/req2_INF.req  )  &> b9_req2_INF.log &
( time srun -N1 -n1 -c1 --nodelist=node3 --time 02:00:00 ./../stverif.sh ../benchmark/straton/benchmark9/benchmark9 ../benchmark/stverif/benchmark9/req3_INF.req  )  &> b9_req3_INF.log &

#benchmark10
( time srun -N1 -n1 -c1 --nodelist=node3 --time 02:00:00 ./../stverif.sh ../benchmark/straton/benchmark10/benchmark10 ../benchmark/stverif/benchmark10/req1_INF.req  )  &> b10_req1_INF.log &
( time srun -N1 -n1 -c1 --nodelist=node3 --time 02:00:00 ./../stverif.sh ../benchmark/straton/benchmark10/benchmark10 ../benchmark/stverif/benchmark10/req2_INF.req  )  &> b10_req2_INF.log &
( time srun -N1 -n1 -c1 --nodelist=node3 --time 02:00:00 ./../stverif.sh ../benchmark/straton/benchmark10/benchmark10 ../benchmark/stverif/benchmark10/req3_INF.req  )  &> b10_req3_INF.log &
( time srun -N1 -n1 -c1 --nodelist=node3 --time 02:00:00 ./../stverif.sh ../benchmark/straton/benchmark10/benchmark10 ../benchmark/stverif/benchmark10/req4_INF.req  )  &> b10_req4_INF.log &
( time srun -N1 -n1 -c1 --nodelist=node3 --time 02:00:00 ./../stverif.sh ../benchmark/straton/benchmark10/benchmark10 ../benchmark/stverif/benchmark10/req5_INF.req  )  &> b10_req5_INF.log &

#benchmark11

( time srun -N1 -n1 -c1 --nodelist=node3 --time 02:00:00 ./../stverif.sh ../benchmark/straton/benchmark11/benchmark11 ../benchmark/stverif/benchmark11/req1_INF.req  )  &> b11_req1_INF.log &
( time srun -N1 -n1 -c1 --nodelist=node3 --time 02:00:00 ./../stverif.sh ../benchmark/straton/benchmark11/benchmark11 ../benchmark/stverif/benchmark11/req2_INF.req  )  &> b11_req2_INF.log &

#benchmark12
( time srun -N1 -n1 -c1 --nodelist=node4 --time 02:00:00 ./../stverif.sh ../benchmark/straton/benchmark12/benchmark12 ../benchmark/stverif/benchmark12/req1_INF.req  )  &> b12_req1_INF.log &

#benchmark13
( time srun -N1 -n1 -c1 --nodelist=node4 --time 02:00:00 ./../stverif.sh ../benchmark/straton/benchmark13/benchmark13 ../benchmark/stverif/benchmark13/req1_INF.req  )  &> b13_req1_INF.log &
( time srun -N1 -n1 -c1 --nodelist=node4 --time 02:00:00 ./../stverif.sh ../benchmark/straton/benchmark13/benchmark13 ../benchmark/stverif/benchmark13/req2_INF.req  )  &> b13_req2_INF.log &
( time srun -N1 -n1 -c1 --nodelist=node4 --time 02:00:00 ./../stverif.sh ../benchmark/straton/benchmark13/benchmark13 ../benchmark/stverif/benchmark13/req3_INF.req  )  &> b13_req3_INF.log &

#benchmark14
( time srun -N1 -n1 -c1 --nodelist=node4 --time 02:00:00 ./../stverif.sh ../benchmark/straton/benchmark14/benchmark14 ../benchmark/stverif/benchmark14/req1_INF.req  )  &> b14_req1_INF.log &
( time srun -N1 -n1 -c1 --nodelist=node4 --time 02:00:00 ./../stverif.sh ../benchmark/straton/benchmark14/benchmark14 ../benchmark/stverif/benchmark14/req2_INF.req  )  &> b14_req2_INF.log &

#benchmark15
( time srun -N1 -n1 -c1 --nodelist=node4 --time 02:00:00 ./../stverif.sh ../benchmark/straton/benchmark15/benchmark15 ../benchmark/stverif/benchmark15/req1_INF.req  )  &> b15_req1_INF.log &

#benchmark16
( time srun -N1 -n1 -c1 --nodelist=node4 --time 02:00:00 ./../stverif.sh ../benchmark/straton/benchmark16/benchmark16 ../benchmark/stverif/benchmark16/req1_INF.req  )  &> b16_req1_INF.log &
( time srun -N1 -n1 -c1 --nodelist=node4 --time 02:00:00 ./../stverif.sh ../benchmark/straton/benchmark16/benchmark16 ../benchmark/stverif/benchmark16/req2_INF.req  )  &> b16_req2_INF.log &
( time srun -N1 -n1 -c1 --nodelist=node4 --time 02:00:00 ./../stverif.sh ../benchmark/straton/benchmark16/benchmark16 ../benchmark/stverif/benchmark16/req3_INF.req  )  &> b16_req3_INF.log &

#benchmark17
( time srun -N1 -n1 -c1 --nodelist=node4 --time 02:00:00 ./../stverif.sh ../benchmark/straton/benchmark17/benchmark17 ../benchmark/stverif/benchmark17/req1_INF.req  )  &> b17_req1_INF.log &

#benchmark18
( time srun -N1 -n1 -c1 --nodelist=node4 --time 02:00:00 ./../stverif.sh ../benchmark/straton/benchmark18/benchmark18 ../benchmark/stverif/benchmark18/req1_INF.req  )  &> b18_req1_INF.log &


: <<'END'
#benchmark MA
( time srun -N1 -n1 -c1 --nodelist=node4 --time 02:00:00 ./../stverif.sh ../benchmark/straton/MA/MA ../benchmark/stverif/MA/MAbenchmark/req1_step2.req  )  &> MA_req1_step2.log &
( time srun -N1 -n1 -c1 --nodelist=node4 --time 02:00:00 ./../stverif.sh ../benchmark/straton/MA/MA ../benchmark/stverif/MA/MAbenchmark/req1_step3.req  )  &> MA_req1_step3.log &
( time srun -N1 -n1 -c1 --nodelist=node4 --time 02:00:00 ./../stverif.sh ../benchmark/straton/MA/MA ../benchmark/stverif/MA/MAbenchmark/req1_step4.req  )  &> MA_req1_step4.log &
( time srun -N1 -n1 -c1 --nodelist=node4 --time 02:00:00 ./../stverif.sh ../benchmark/straton/MA/MA ../benchmark/stverif/MA/MAbenchmark/req1_step5.req  )  &> MA_req1_step5.log &
( time srun -N1 -n1 -c1 --nodelist=node4 --time 02:00:00 ./../stverif.sh ../benchmark/straton/MA/MA ../benchmark/stverif/MA/MAbenchmark/req2_step2.req  )  &> MA_req2_step2.log &
( time srun -N1 -n1 -c1 --nodelist=node4 --time 02:00:00 ./../stverif.sh ../benchmark/straton/MA/MA ../benchmark/stverif/MA/MAbenchmark/req2_step3.req  )  &> MA_req2_step3.log &
( time srun -N1 -n1 -c1 --nodelist=node4 --time 02:00:00 ./../stverif.sh ../benchmark/straton/MA/MA ../benchmark/stverif/MA/MAbenchmark/req2_step4.req  )  &> MA_req2_step4.log &
( time srun -N1 -n1 -c1 --nodelist=node4 --time 02:00:00 ./../stverif.sh ../benchmark/straton/MA/MA ../benchmark/stverif/MA/MAbenchmark/req2_step5.req  )  &> MA_req2_step5.log &
( time srun -N1 -n1 -c1 --nodelist=node4 --time 02:00:00 ./../stverif.sh ../benchmark/straton/MA/MA ../benchmark/stverif/MA/MAbenchmark/req3_step2.req  )  &> MA_req3_step2.log &
( time srun -N1 -n1 -c1 --nodelist=node4 --time 02:00:00 ./../stverif.sh ../benchmark/straton/MA/MA ../benchmark/stverif/MA/MAbenchmark/req3_step3.req  )  &> MA_req3_step3.log &
( time srun -N1 -n1 -c1 --nodelist=node4 --time 02:00:00 ./../stverif.sh ../benchmark/straton/MA/MA ../benchmark/stverif/MA/MAbenchmark/req3_step4.req  )  &> MA_req3_step4.log &
( time srun -N1 -n1 -c1 --nodelist=node4 --time 02:00:00 ./../stverif.sh ../benchmark/straton/MA/MA ../benchmark/stverif/MA/MAbenchmark/req3_step5.req  )  &> MA_req3_step5.log &

#benchmark PMS
( time srun -N1 -n1 -c1 --nodelist=node4 --time 02:00:00 ./../stverif.sh ../benchmark/straton/PMS/PMSEmulator ../benchmark/stverif/PMS/PMSEbenchmark/req1_step2.req )  &> PMS_req1_step2.log &
( time srun -N1 -n1 -c1 --nodelist=node4 --time 02:00:00 ./../stverif.sh ../benchmark/straton/PMS/PMSEmulator ../benchmark/stverif/PMS/PMSEbenchmark/req2_step2.req )  &> PMS_req2_step2.log &
( time srun -N1 -n1 -c1 --nodelist=node4 --time 02:00:00 ./../stverif.sh ../benchmark/straton/PMS/PMSEmulator ../benchmark/stverif/PMS/PMSEbenchmark/req3_step2.req )  &> PMS_req3_step2.log &
( time srun -N1 -n1 -c1 --nodelist=node4 --time 02:00:00 ./../stverif.sh ../benchmark/straton/PMS/PMSEmulator ../benchmark/stverif/PMS/PMSEbenchmark/req4_step2.req )  &> PMS_req4_step2.log &
( time srun -N1 -n1 -c1 --nodelist=node4 --time 02:00:00 ./../stverif.sh ../benchmark/straton/PMS/PMSEmulator ../benchmark/stverif/PMS/PMSEbenchmark/req5_step2.req )  &> PMS_req5_step2.log &
( time srun -N1 -n1 -c1 --nodelist=node4 --time 02:00:00 ./../stverif.sh ../benchmark/straton/PMS/PMSEmulator ../benchmark/stverif/PMS/PMSEbenchmark/req6_step2.req )  &> PMS_req6_step2.log &
( time srun -N1 -n1 -c1 --nodelist=node4 --time 02:00:00 ./../stverif.sh ../benchmark/straton/PMS/PMSEmulator ../benchmark/stverif/PMS/PMSEbenchmark/req7_step2.req )  &> PMS_req7_step2.log &
( time srun -N1 -n1 -c1 --nodelist=node4 --time 02:00:00 ./../stverif.sh ../benchmark/straton/PMS/PMSEmulator ../benchmark/stverif/PMS/PMSEbenchmark/req8_step2.req )  &> PMS_req8_step2.log &
( time srun -N1 -n1 -c1 --nodelist=node5 --time 02:00:00 ./../stverif.sh ../benchmark/straton/PMS/PMSEmulator ../benchmark/stverif/PMS/PMSEbenchmark/req9_step2.req )  &> PMS_req9_step2.log &
( time srun -N1 -n1 -c1 --nodelist=node5 --time 02:00:00 ./../stverif.sh ../benchmark/straton/PMS/PMSEmulator ../benchmark/stverif/PMS/PMSEbenchmark/req10_step2.req )  &> PMS_req10_step2.log & 

( time srun -N1 -n1 -c1 --nodelist=node5 --time 02:00:00 ./../stverif.sh ../benchmark/straton/PMS/PMSEmulator ../benchmark/stverif/PMS/PMSEbenchmark/req1_step3.req )  &> PMS_req1_step3.log & 
( time srun -N1 -n1 -c1 --nodelist=node5 --time 02:00:00 ./../stverif.sh ../benchmark/straton/PMS/PMSEmulator ../benchmark/stverif/PMS/PMSEbenchmark/req2_step3.req )  &> PMS_req2_step3.log & 
( time srun -N1 -n1 -c1 --nodelist=node5 --time 02:00:00 ./../stverif.sh ../benchmark/straton/PMS/PMSEmulator ../benchmark/stverif/PMS/PMSEbenchmark/req3_step3.req )  &> PMS_req3_step3.log & 
( time srun -N1 -n1 -c1 --nodelist=node5 --time 02:00:00 ./../stverif.sh ../benchmark/straton/PMS/PMSEmulator ../benchmark/stverif/PMS/PMSEbenchmark/req4_step3.req )  &> PMS_req4_step3.log & 
( time srun -N1 -n1 -c1 --nodelist=node5 --time 02:00:00 ./../stverif.sh ../benchmark/straton/PMS/PMSEmulator ../benchmark/stverif/PMS/PMSEbenchmark/req5_step3.req )  &> PMS_req5_step3.log & 
( time srun -N1 -n1 -c1 --nodelist=node5 --time 02:00:00 ./../stverif.sh ../benchmark/straton/PMS/PMSEmulator ../benchmark/stverif/PMS/PMSEbenchmark/req6_step3.req )  &> PMS_req6_step3.log & 
( time srun -N1 -n1 -c1 --nodelist=node5 --time 02:00:00 ./../stverif.sh ../benchmark/straton/PMS/PMSEmulator ../benchmark/stverif/PMS/PMSEbenchmark/req7_step3.req )  &> PMS_req7_step3.log & 
( time srun -N1 -n1 -c1 --nodelist=node5 --time 02:00:00 ./../stverif.sh ../benchmark/straton/PMS/PMSEmulator ../benchmark/stverif/PMS/PMSEbenchmark/req8_step3.req )  &> PMS_req8_step3.log & 
( time srun -N1 -n1 -c1 --nodelist=node5 --time 02:00:00 ./../stverif.sh ../benchmark/straton/PMS/PMSEmulator ../benchmark/stverif/PMS/PMSEbenchmark/req9_step3.req )  &> PMS_req9_step3.log & 
( time srun -N1 -n1 -c1 --nodelist=node5 --time 02:00:00 ./../stverif.sh ../benchmark/straton/PMS/PMSEmulator ../benchmark/stverif/PMS/PMSEbenchmark/req10_step3.req )  &> PMS_req10_step3.log & 

( time srun -N1 -n1 -c1 --nodelist=node5 --time 02:00:00 ./../stverif.sh ../benchmark/straton/PMS/PMSEmulator ../benchmark/stverif/PMS/PMSEbenchmark/req1_step4.req )  &> PMS_req1_step4.log & 
( time srun -N1 -n1 -c1 --nodelist=node5 --time 02:00:00 ./../stverif.sh ../benchmark/straton/PMS/PMSEmulator ../benchmark/stverif/PMS/PMSEbenchmark/req2_step4.req )  &> PMS_req2_step4.log & 
( time srun -N1 -n1 -c1 --nodelist=node5 --time 02:00:00 ./../stverif.sh ../benchmark/straton/PMS/PMSEmulator ../benchmark/stverif/PMS/PMSEbenchmark/req3_step4.req )  &> PMS_req3_step4.log & 
( time srun -N1 -n1 -c1 --nodelist=node5 --time 02:00:00 ./../stverif.sh ../benchmark/straton/PMS/PMSEmulator ../benchmark/stverif/PMS/PMSEbenchmark/req4_step4.req )  &> PMS_req4_step4.log & 
( time srun -N1 -n1 -c1 --nodelist=node5 --time 02:00:00 ./../stverif.sh ../benchmark/straton/PMS/PMSEmulator ../benchmark/stverif/PMS/PMSEbenchmark/req5_step4.req )  &> PMS_req5_step4.log & 
( time srun -N1 -n1 -c1 --nodelist=node5 --time 02:00:00 ./../stverif.sh ../benchmark/straton/PMS/PMSEmulator ../benchmark/stverif/PMS/PMSEbenchmark/req6_step4.req )  &> PMS_req6_step4.log & 
( time srun -N1 -n1 -c1 --nodelist=node5 --time 02:00:00 ./../stverif.sh ../benchmark/straton/PMS/PMSEmulator ../benchmark/stverif/PMS/PMSEbenchmark/req7_step4.req )  &> PMS_req7_step4.log & 
( time srun -N1 -n1 -c1 --nodelist=node5 --time 02:00:00 ./../stverif.sh ../benchmark/straton/PMS/PMSEmulator ../benchmark/stverif/PMS/PMSEbenchmark/req8_step4.req )  &> PMS_req8_step4.log & 
( time srun -N1 -n1 -c1 --nodelist=node5 --time 02:00:00 ./../stverif.sh ../benchmark/straton/PMS/PMSEmulator ../benchmark/stverif/PMS/PMSEbenchmark/req9_step4.req )  &> PMS_req9_step4.log & 
( time srun -N1 -n1 -c1 --nodelist=node5 --time 02:00:00 ./../stverif.sh ../benchmark/straton/PMS/PMSEmulator ../benchmark/stverif/PMS/PMSEbenchmark/req10_step4.req )  &> PMS_req10_step4.log & 

( time srun -N1 -n1 -c1 --nodelist=node5 --time 02:00:00 ./../stverif.sh ../benchmark/straton/PMS/PMSEmulator ../benchmark/stverif/PMS/PMSEbenchmark/req1_step5.req )  &> PMS_req1_step5.log & 
( time srun -N1 -n1 -c1 --nodelist=node5 --time 02:00:00 ./../stverif.sh ../benchmark/straton/PMS/PMSEmulator ../benchmark/stverif/PMS/PMSEbenchmark/req2_step5.req )  &> PMS_req2_step5.log & 
( time srun -N1 -n1 -c1 --nodelist=node5 --time 02:00:00 ./../stverif.sh ../benchmark/straton/PMS/PMSEmulator ../benchmark/stverif/PMS/PMSEbenchmark/req3_step5.req )  &> PMS_req3_step5.log &
( time srun -N1 -n1 -c1 --nodelist=node5 --time 02:00:00 ./../stverif.sh ../benchmark/straton/PMS/PMSEmulator ../benchmark/stverif/PMS/PMSEbenchmark/req4_step5.req )  &> PMS_req4_step5.log & 
( time srun -N1 -n1 -c1 --nodelist=node5 --time 02:00:00 ./../stverif.sh ../benchmark/straton/PMS/PMSEmulator ../benchmark/stverif/PMS/PMSEbenchmark/req5_step5.req )  &> PMS_req5_step5.log & 
( time srun -N1 -n1 -c1 --nodelist=node5 --time 02:00:00 ./../stverif.sh ../benchmark/straton/PMS/PMSEmulator ../benchmark/stverif/PMS/PMSEbenchmark/req6_step5.req )  &> PMS_req6_step5.log & 
( time srun -N1 -n1 -c1 --nodelist=node5 --time 02:00:00 ./../stverif.sh ../benchmark/straton/PMS/PMSEmulator ../benchmark/stverif/PMS/PMSEbenchmark/req7_step5.req )  &> PMS_req7_step5.log & 
( time srun -N1 -n1 -c1 --nodelist=node5 --time 02:00:00 ./../stverif.sh ../benchmark/straton/PMS/PMSEmulator ../benchmark/stverif/PMS/PMSEbenchmark/req8_step5.req )  &> PMS_req8_step5.log & 
( time srun -N1 -n1 -c1 --nodelist=node5 --time 02:00:00 ./../stverif.sh ../benchmark/straton/PMS/PMSEmulator ../benchmark/stverif/PMS/PMSEbenchmark/req9_step5.req )  &> PMS_req9_step5.log & 
( time srun -N1 -n1 -c1 --nodelist=node5 --time 02:00:00 ./../stverif.sh ../benchmark/straton/PMS/PMSEmulator ../benchmark/stverif/PMS/PMSEbenchmark/req10_step5.req )  &> PMS_req10_step5.log &  
END
