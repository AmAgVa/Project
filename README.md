# About
This is a collaborative project by Thu Ha Thai, Amanda Aghai Vafaei, Nathaly Johansson, and Simon Göransson where datasets from SMHI have been used.

With the use of datasets available from www.SMHI.se the answers were divided into subtasks. Here the work has been approached by policy A where the release manager controls the flow of pull requests made to the upstream main file. 

# Remark on cleaning data file

After extraction of the tarball `datasets.tgz` by using the command
``` 
tar zxvf datasets.tgz
```
The data of Lund temperatures is picked out and changed the name into 'opendata_Lund.csv' for the convenience of later reference. The first 13 rows of the file contain data that are unnecessary for this analysis therefore they are removed using the command 
```
sed -e '1d' -e '2d' -e '3d' -e '4d' -e '5d' -e '6d' -e '7d' -e '8d' -e '9d' -e '10d' -e '11d' -e '12d' -e '13d' opendata_Lund.csv > cleaned_Lund.csv
```
All columns except the first column (contains data about the date of the measurement), the second column (contains data about the time of the measurement), and the third column (contains data about the temperature measured) are all removed by the command
```
awk -F ';' '{print $1 ";" $2 ";" $3}' cleaned_Lund.csv > cleaneddata_Lund.csv
```
And we ended up with the file 'cleaneddata_Lund.csv' which we use for analysis in C++.

The file cleaneddata_Lulea.csv is the cleaned version of opendata.Lulea.csv

It was made in a similar fashion as the file cleandata_Lund.csv, by using the bash commands sed, grep, awk and cut.

# Remark on compiling 

One can just follow this order 
```
make
```
make would have produces an excutable called main which can be excuted by doing 
```
./main datasets/cleanneddata_Lund.csv datasets/cleanneddata_Lulea.csv 2021
```
once that is done one must procceed to launch root and follow the instructions below.

# Remark on ROOT

Once inside an apptainer and inside root, the code can be loaded and executed using the command
```
.L seasonal.C
.L year_temp_anlys.C
.L Histograms.C
draw_seasonal_averages()
year_temp_anlys()
histogram()
```


