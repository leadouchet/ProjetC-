#==========================================================================================================================
#               GRAPHICAL REPRESENTATION 
#==========================================================================================================================
 
#change directory
setwd("/home/fperon/Documents/C/Projet/ProjetC-")

#data importation from csv file
data = read.table("dataTest.csv",header=T)
summary(data)

A=seq(0,50,5)

data=data["nb_B"]

sol=c()
for (i in 1:66){sol[i]=as.vector(data[i,])}
T=seq(0,1500,300)

B=as.matrix(sol,nrow = 6, ncol=11)

heatmap(x=B, Rowv = T,Colv=A)
# Data treatment 
status = levels(data[,3]) 
color = c("red", "blue", "green")

# Plot of the results
for (i in 1:3){
  if (i == 1){
    plot(data[data[,3] == status[i],2],data[data[,3] == status[i],1], pch = 20, col = color[i], xlim = c(0,10), 
         ylim = c(0,1500), xlab = "A_init", ylab = "T")
    legend("topright",legend = status, pch = 20, col = color[1:length(status)])
  }
  else {
    points(data[data[,3] == status[i],2], data[data[,3] == status[i],1], pch = 20, col = color[i])
  }
}
 