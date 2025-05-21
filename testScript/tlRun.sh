timeout 2h ./../analysis.sh ../apps/trafficLight.st ../apps/caseStudy-1.req   &> tl11.log &
sleep 2s;
timeout 2h ./../analysis.sh ../apps/trafficLight.st ../apps/caseStudy-2.req   &> tl12.log &
sleep 2s;
timeout 2h ./../analysis.sh ../apps/tl2.st ../apps/c2-1.req   &> tl21.log &
sleep 2s;
timeout 2h ./../analysis.sh ../apps/tl2.st ../apps/c2-2.req   &> tl22.log &
sleep 2s;
timeout 2h ./../analysis.sh ../apps/tl3.st ../apps/c3-1.req   &> tl31.log &
sleep 2s;
timeout 2h ./../analysis.sh ../apps/tl3.st ../apps/c3-2.req   &> tl32.log &
sleep 2s;
timeout 2h ./../analysis.sh ../apps/tl4.st ../apps/c4-1.req   &> tl41.log &
sleep 2s;
timeout 2h ./../analysis.sh ../apps/tl5.st ../apps/c5-1.req   &> tl51.log &
sleep 2s;
timeout 2h ./../analysisNM.sh ../apps/trafficLight.st ../apps/caseStudy-1.req   &> tln11.log &
sleep 2s;
timeout 2h ./../analysisNM.sh ../apps/trafficLight.st ../apps/caseStudy-2.req   &> tln12.log &
sleep 2s;
timeout 2h ./../analysisNM.sh ../apps/tl2.st ../apps/c2-1.req   &> tln21.log &
sleep 2s;
timeout 2h ./../analysisNM.sh ../apps/tl2.st ../apps/c2-2.req   &> tln22.log &
sleep 2s;
timeout 2h ./../analysisNM.sh ../apps/tl3.st ../apps/c3-1.req   &> tln31.log &
sleep 2s;
timeout 2h ./../analysisNM.sh ../apps/tl3.st ../apps/c3-2.req   &> tln32.log &
sleep 2s;
timeout 2h ./../analysisNM.sh ../apps/tl4.st ../apps/c4-1.req   &> tln41.log &
sleep 2s;
timeout 2h ./../analysisNM.sh ../apps/tl5.st ../apps/c5-1.req   &> tln51.log &
sleep 2s;
