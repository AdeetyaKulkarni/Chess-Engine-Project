#include <iostream>
#include<set>
#include<tuple>
#include "project1.h"
using namespace std;
//move is mov
struct mov{
	string src;
	string dest;

	bool operator <(const mov& pmove) const
	{
		return(src < pmove.src) || ((!(pmove.src < src)) && (dest < pmove.dest));
	}

};

//struct color
struct color{
  string c;
};

//Check occupied function:
int occupied(int r,int f,position P){

  string temp = P[r][f];
  if( temp != "e"){
    return 1;
  }
  else{
      return 0;
  }
}

//Part of All moves
set<mov> allif(string s, string d, mov pmove, set<mov> Curset,int f, int j, int r, int i){

  //convert file to ascii letters
        string newf(1,char(f+97));
        string newj(1,char(j+97));
        //append to string 
        s.erase(s.begin(),s.end());
        s.append(to_string(r));
        s.append(newf);
        d.erase(d.begin(),d.end());
        d.append(to_string(i));
        d.append(newj);
        //add string to struct
        pmove.src = s;
        pmove.dest = d;
        //append move to set
        Curset.insert(pmove);
        return Curset;

}

//Bishopmoves
tuple<set<mov>,set<mov>> Bishopmoves(int r, int f, position P,string PC, set<mov>Covermoves, int jack){

 set<mov> BMset;
 set<mov> tempcover;
 string occupiedpstr;
 string s;//source
 string d;//dest
 mov pmove;
 int occ = 0;
 int i;
 int j;

 //1
    i=r;
    j=f;
    
    while(i<=7 && i>=0 && j<=7 && j>=0){
      
      //cout << "1st enter";
      //Edge cases
      if(i==7){break;}
      else{i++;}
      if(j==0){break;}
      else{j--;}
      
      occ = occupied(i,j,P);
      //cout<<"occ =" << occ;
      if(occ!=1){

        BMset = allif(s, d, pmove, BMset,f,j,r,i);

      }
      
      else{
        //check if that piece is our or enemy
        occupiedpstr = string(P[i][j]);
        if(occupiedpstr[0] == PC[0]){

          if(jack==1){
            //cout << "Chala1";
            tempcover = allif(s, d, pmove, Covermoves,f,j,r,i);   
             set<mov>::const_iterator it;
             for (it = tempcover.begin(); it != tempcover.end(); it++) 
            {
                Covermoves.insert((*it));
            }
            tempcover.clear();
          }
        
          break;//if our dont append and moves done for this way
        }
        else{ //if enemy append
            //convert file to ascii letters
        string newf(1,char(f+97));
        string newj(1,char(j+97));
        //append to string 
        
        s.erase(s.begin(),s.end());
        s.append(to_string(r));
        s.append(newf);
        d.erase(d.begin(),d.end());
        d.append(to_string(i));
        d.append(newj);
        //add string to struct
        pmove.src = s;
        pmove.dest = d;
        //append move to set
        BMset.insert(pmove);
        break;
        }
        
       
      }
    }
     //2
     
    i=r;
    j=f;
    while(i<=7 && i>=0 && j<=7 && j>=0 ){
      
      //Edge 
      if(i==7){break;}
      else{i++;}
      if(j==7){break;}
      else{j++;}

      occ = occupied(i,j,P);
      if(occ!=1){

        BMset = allif(s, d, pmove, BMset,f,j,r,i);
       

      }
      else{

        //check if that piece is our or enemy
        occupiedpstr = string(P[i][j]);
        if(occupiedpstr[0] == PC[0]){

           if(jack==1){
            //cout << "Chala2";
            tempcover = allif(s, d, pmove, Covermoves,f,j,r,i);   
             set<mov>::const_iterator it;
             for (it = tempcover.begin(); it != tempcover.end(); it++) 
            {
                //cout << (*it).src <<"-" << (*it).dest << "\n\n";
                Covermoves.insert((*it));
                
            }
            tempcover.clear();
          }

          break;//if our dont append and moves done for this way
        }
        else{ //if enemy append
            //convert file to ascii letters
        string newf(1,char(f+97));
        string newj(1,char(j+97));
        //append to string 
        s.erase(s.begin(),s.end());
        s.append(to_string(r));
        s.append(newf);
        d.erase(d.begin(),d.end());
        d.append(to_string(i));
        d.append(newj);
        //add string to struct
        pmove.src = s;
        pmove.dest = d;
        //append move to set
        BMset.insert(pmove);
        break;
        }
        
        
      }
    }
      

     //3
      i=r;
      j=f;
    while(i<=7 && i>=0 && j<=7 && j>=0 ){
      
      //Edge cases
      if(i==0){break;}
      else{i--;}
      if(j==7){break;}
      else{j++;}

      occ = occupied(i,j,P);
      if(occ!=1){
        
        BMset = allif(s, d, pmove, BMset,f,j,r,i);

      }
      else{
        
        //check if that piece is our or enemy
        occupiedpstr = string(P[i][j]);
        if(occupiedpstr[0] == PC[0]){

           if(jack==1){
           // cout << "Chala3";
            tempcover = allif(s, d, pmove, Covermoves,f,j,r,i);   
             set<mov>::const_iterator it;
             for (it = tempcover.begin(); it != tempcover.end(); it++) 
            {
                Covermoves.insert((*it));
            }
            tempcover.clear();
          }

          break;//if our dont append and moves done for this way
        }
        else{ //if enemy append
            //convert file to ascii letters
        string newf(1,char(f+97));
        string newj(1,char(j+97));
        //append to string 
        s.erase(s.begin(),s.end());
        s.append(to_string(r));
        s.append(newf);
        d.erase(d.begin(),d.end());
        d.append(to_string(i));
        d.append(newj);
        //add string to struct
        pmove.src = s;
        pmove.dest = d;
        //append move to set
        BMset.insert(pmove);
        break;
        }
        

      }

    }
     //4
     i=r;
     j=f;
    while(i<=7 && i>=0 && j<=7 && j>=0){
      
      //Edge cases:1
      if(i==0){break;}
      else{i--;}
      if(j==0){break;}
      else{j--;}
      occ = occupied(i,j,P);
      if(occ!=1){
        
        BMset = allif(s, d, pmove, BMset,f,j,r,i);
        
      }
      else{
        
        //check if that piece is our or enemy
        occupiedpstr = string(P[i][j]);
        if(occupiedpstr[0] == PC[0]){

           if(jack==1){
            //cout << "Chala4";
            tempcover = allif(s, d, pmove, Covermoves,f,j,r,i);   
             set<mov>::const_iterator it;
             for (it = tempcover.begin(); it != tempcover.end(); it++) 
            {
                Covermoves.insert((*it));
            }
            tempcover.clear();
          }
          break;//if our dont append and moves done for this way
        }
        else{ //if enemy append
            //convert file to ascii letters
        string newf(1,char(f+97));
        string newj(1,char(j+97));
        //append to string
        s.erase(s.begin(),s.end());
        s.append(to_string(r));
        s.append(newf);
        d.erase(d.begin(),d.end());
        d.append(to_string(i));
        d.append(newj);
        //add string to struct
        pmove.src = s;
        pmove.dest = d;
        //append move to set
        BMset.insert(pmove);
        break;
        }
        

      }
    }


  return make_tuple(BMset,Covermoves); 
}

//Rookmoves
tuple<set<mov>,set<mov>> Rookmoves(int r,int f,position P,string PC,set<mov>Covermoves, int jack){

 set<mov> RKset;
 string occupiedpstr;
 set<mov> tempcover;
 string s;//source
 string d;//dest
 mov pmove;
 int occ = 0;
 int i;
 int j;

 //1
    i=r;
    j=f;
    
    while(i<=7 && i>=0){
      
      //cout << "1st enter";
      //Edge cases
      if(i==0){break;}
      else{i--;}
      
      occ = occupied(i,j,P);
      //cout<<"occ =" << occ;
      if(occ!=1){

        RKset = allif(s, d, pmove, RKset,f,j,r,i);

      }
      
      else{
        //check if that piece is our or enemy
        occupiedpstr = string(P[i][j]);
        if(occupiedpstr[0] == PC[0]){
          
          if(jack==1){
           // cout << "Chala1";
            tempcover = allif(s, d, pmove, Covermoves,f,j,r,i);   
             set<mov>::const_iterator it;
             for (it = tempcover.begin(); it != tempcover.end(); it++) 
            {
                Covermoves.insert((*it));
            }
            tempcover.clear();
          }
        

          break;//if our dont append and moves done for this way
        }
        else{ //if enemy append
            //convert file to ascii letters
        string newf(1,char(f+97));
        string newj(1,char(j+97));
        //append to string 
        
        s.erase(s.begin(),s.end());
        s.append(to_string(r));
        s.append(newf);
        d.erase(d.begin(),d.end());
        d.append(to_string(i));
        d.append(newj);
        //add string to struct
        pmove.src = s;
        pmove.dest = d;
        //append move to set
        RKset.insert(pmove);
        break;
        }
        
       
      }
    }
     //2
     
    i=r;
    j=f;
    while(i<=7 && i>=0){
      
      //Edge 
      if(i==7){break;}
      else{i++;}

      occ = occupied(i,j,P);
      if(occ!=1){

        RKset = allif(s, d, pmove, RKset,f,j,r,i);
       

      }
      else{

        //check if that piece is our or enemy
        occupiedpstr = string(P[i][j]);
        if(occupiedpstr[0] == PC[0]){

          if(jack==1){
            //cout << "Chala2";
            tempcover = allif(s, d, pmove, Covermoves,f,j,r,i);   
             set<mov>::const_iterator it;
             for (it = tempcover.begin(); it != tempcover.end(); it++) 
            {
                Covermoves.insert((*it));
            }
            tempcover.clear();
          }
        


          break;//if our dont append and moves done for this way
        }
        else{ //if enemy append
            //convert file to ascii letters
        string newf(1,char(f+97));
        string newj(1,char(j+97));
        //append to string 
        s.erase(s.begin(),s.end());
        s.append(to_string(r));
        s.append(newf);
        d.erase(d.begin(),d.end());
        d.append(to_string(i));
        d.append(newj);
        //add string to struct
        pmove.src = s;
        pmove.dest = d;
        //append move to set
        RKset.insert(pmove);
        break;
        }
        
        
      }
    }
      

     //3
      i=r;
      j=f;
    while(j<=7 && j>=0){
      
      //Edge cases
      if(j==0){break;}
      else{j--;}


      occ = occupied(i,j,P);
      if(occ!=1){
        
        RKset = allif(s, d, pmove, RKset,f,j,r,i);

      }
      else{
        
        //check if that piece is our or enemy
        occupiedpstr = string(P[i][j]);
        if(occupiedpstr[0] == PC[0]){
          
          if(jack==1){
            //cout << "Chala3";
            tempcover = allif(s, d, pmove, Covermoves,f,j,r,i);   
             set<mov>::const_iterator it;
             for (it = tempcover.begin(); it != tempcover.end(); it++) 
            {
                Covermoves.insert((*it));
            }
            tempcover.clear();
          }
        

          break;//if our dont append and moves done for this way
        }
        else{ //if enemy append
            //convert file to ascii letters
        string newf(1,char(f+97));
        string newj(1,char(j+97));
        //append to string 
        s.erase(s.begin(),s.end());
        s.append(to_string(r));
        s.append(newf);
        d.erase(d.begin(),d.end());
        d.append(to_string(i));
        d.append(newj);
        //add string to struct
        pmove.src = s;
        pmove.dest = d;
        //append move to set
        RKset.insert(pmove);
        break;
        }
        

      }

    }
     //4
     i=r;
     j=f;
    while(j<=7 && j>=0){
      
      //Edge cases:1
      if(j==7){break;}
      else{j++;}

      occ = occupied(i,j,P);
      if(occ!=1){
        
        RKset = allif(s, d, pmove, RKset,f,j,r,i);
        
      }
      else{
        
        //check if that piece is our or enemy
        occupiedpstr = string(P[i][j]);
        if(occupiedpstr[0] == PC[0]){

          if(jack==1){
            //cout << "Chala4";
            tempcover = allif(s, d, pmove, Covermoves,f,j,r,i);   
             set<mov>::const_iterator it;
             for (it = tempcover.begin(); it != tempcover.end(); it++) 
            {
                Covermoves.insert((*it));
            }
            tempcover.clear();
          }
        

          break;//if our dont append and moves done for this way
        }
        else{ //if enemy append
            //convert file to ascii letters
        string newf(1,char(f+97));
        string newj(1,char(j+97));
        //append to string
        
        s.append(to_string(r));
        s.append(newf);
        d.append(to_string(i));
        d.append(newj);
        //add string to struct
        pmove.src = s;
        pmove.dest = d;
        //append move to set
        RKset.insert(pmove);
        break;
        }
        

      }
    }


  
  return make_tuple(RKset,Covermoves); 

}

//Knightmoves
tuple<set<mov>,set<mov>> Knightmoves(int r,int f, position P, string PC,set<mov>Covermoves, int jack){

 set<mov> KMset;
 string occupiedpstr;
 set<mov> tempcover;
 string s;//source
 string d;//dest
 mov pmove;
 int occ = 0;
 int i;
 int j;
 
 //#1
 i = r;
 j = f;
 for(int temp=0; temp<1; temp++)
 {
   if(i==0 || i==1 || j==7){break;}
   else{i-=2; j++;}

   occ = occupied(i,j,P);

   if (occ!=1){

     KMset = allif(s,d,pmove,KMset,f,j,r,i);

   } 
   else{

     //check if that piece is our or enemy
        occupiedpstr = string(P[i][j]);
        if(occupiedpstr[0] == PC[0]){

          if(jack==1){
            //cout << "Chala1";
            tempcover = allif(s, d, pmove, Covermoves,f,j,r,i);   
             set<mov>::const_iterator it;
             for (it = tempcover.begin(); it != tempcover.end(); it++) 
            {
                Covermoves.insert((*it));
            }
            tempcover.clear();
          }

          break;//if our dont append and moves done for this way
        }
        else{ //if enemy append
            //convert file to ascii letters
        string newf(1,char(f+97));
        string newj(1,char(j+97));
        //append to string 
        
        s.erase(s.begin(),s.end());
        s.append(to_string(r));
        s.append(newf);
        d.erase(d.begin(),d.end());
        d.append(to_string(i));
        d.append(newj);
        //add string to struct
        pmove.src = s;
        pmove.dest = d;
        //append move to set
        KMset.insert(pmove);
        break;
       }  
     }
 
  }

   //#2
 i = r;
 j = f;
 for(int temp=0; temp<1; temp++)
 {
   if(i==0 || j==6 || j==7){break;}
   else{i--; j+=2;}

   occ = occupied(i,j,P);

   if (occ!=1){

     KMset = allif(s,d,pmove,KMset,f,j,r,i);

   } 
   else{

     //check if that piece is our or enemy
        occupiedpstr = string(P[i][j]);
        if(occupiedpstr[0] == PC[0]){

          if(jack==1){
            //cout << "Chala2";
            tempcover = allif(s, d, pmove, Covermoves,f,j,r,i);   
             set<mov>::const_iterator it;
             for (it = tempcover.begin(); it != tempcover.end(); it++) 
            {
                Covermoves.insert((*it));
            }
            tempcover.clear();
          }

          break;//if our dont append and moves done for this way
        }
        else{ //if enemy append
            //convert file to ascii letters
        string newf(1,char(f+97));
        string newj(1,char(j+97));
        //append to string 
        
        s.erase(s.begin(),s.end());
        s.append(to_string(r));
        s.append(newf);
        d.erase(d.begin(),d.end());
        d.append(to_string(i));
        d.append(newj);
        //add string to struct
        pmove.src = s;
        pmove.dest = d;
        //append move to set
        KMset.insert(pmove);
        break;
       }  
     }
 
  }


  //#3
 i = r;
 j = f;
 for(int temp=0; temp<1; temp++)
 {
   if(i==7 || j==6 || j==7){break;}
   else{i++; j+=2;}

   occ = occupied(i,j,P);

   if (occ!=1){

     KMset = allif(s,d,pmove,KMset,f,j,r,i);

   } 
   else{

     //check if that piece is our or enemy
        occupiedpstr = string(P[i][j]);
        if(occupiedpstr[0] == PC[0]){

          if(jack==1){
            //cout << "Chala3";
            tempcover = allif(s, d, pmove, Covermoves,f,j,r,i);   
             set<mov>::const_iterator it;
             for (it = tempcover.begin(); it != tempcover.end(); it++) 
            {
                Covermoves.insert((*it));
            }
            tempcover.clear();
          }

          break;//if our dont append and moves done for this way
        }
        else{ //if enemy append
            //convert file to ascii letters
        string newf(1,char(f+97));
        string newj(1,char(j+97));
        //append to string 
        
        s.erase(s.begin(),s.end());
        s.append(to_string(r));
        s.append(newf);
        d.erase(d.begin(),d.end());
        d.append(to_string(i));
        d.append(newj);
        //add string to struct
        pmove.src = s;
        pmove.dest = d;
        //append move to set
        KMset.insert(pmove);
        break;
       }  
     }
 
  }


  //#4
 i = r;
 j = f;
 for(int temp=0; temp<1; temp++)
 {
   if(i==6 || i==7 || j==7){break;}
   else{i+=2; j++;}

   occ = occupied(i,j,P);

   if (occ!=1){

     KMset = allif(s,d,pmove,KMset,f,j,r,i);

   } 
   else{

     //check if that piece is our or enemy
        occupiedpstr = string(P[i][j]);
        if(occupiedpstr[0] == PC[0]){

          if(jack==1){
            //cout << "Chala4";
            tempcover = allif(s, d, pmove, Covermoves,f,j,r,i);   
             set<mov>::const_iterator it;
             for (it = tempcover.begin(); it != tempcover.end(); it++) 
            {
                Covermoves.insert((*it));
            }
            tempcover.clear();
          }

          break;//if our dont append and moves done for this way
        }
        else{ //if enemy append
            //convert file to ascii letters
        string newf(1,char(f+97));
        string newj(1,char(j+97));
        //append to string 
        
        s.erase(s.begin(),s.end());
        s.append(to_string(r));
        s.append(newf);
        d.erase(d.begin(),d.end());
        d.append(to_string(i));
        d.append(newj);
        //add string to struct
        pmove.src = s;
        pmove.dest = d;
        //append move to set
        KMset.insert(pmove);
        break;
       }  
     }
 
  }


  //#5
 i = r;
 j = f;
 for(int temp=0; temp<1; temp++)
 {
   if(i==6 || i==7 || j==0){break;}
   else{i+=2; j--;}

   occ = occupied(i,j,P);

   if (occ!=1){

     KMset = allif(s,d,pmove,KMset,f,j,r,i);

   } 
   else{

     //check if that piece is our or enemy
        occupiedpstr = string(P[i][j]);
        if(occupiedpstr[0] == PC[0]){
          
          if(jack==1){
            //cout << "Chala5";
            tempcover = allif(s, d, pmove, Covermoves,f,j,r,i);   
             set<mov>::const_iterator it;
             for (it = tempcover.begin(); it != tempcover.end(); it++) 
            {
                Covermoves.insert((*it));
            }
            tempcover.clear();
          }

          break;//if our dont append and moves done for this way
        }
        else{ //if enemy append
            //convert file to ascii letters
        string newf(1,char(f+97));
        string newj(1,char(j+97));
        //append to string 
        
        s.erase(s.begin(),s.end());
        s.append(to_string(r));
        s.append(newf);
        d.erase(d.begin(),d.end());
        d.append(to_string(i));
        d.append(newj);
        //add string to struct
        pmove.src = s;
        pmove.dest = d;
        //append move to set
        KMset.insert(pmove);
        break;
       }  
     }
 
  }


  //#6
 i = r;
 j = f;
 for(int temp=0; temp<1; temp++)
 {
   if(i==7 || j==0 || j==1){break;}
   else{i++; j-=2;}

   occ = occupied(i,j,P);

   if (occ!=1){

     KMset = allif(s,d,pmove,KMset,f,j,r,i);

   } 
   else{

     //check if that piece is our or enemy
        occupiedpstr = string(P[i][j]);
        if(occupiedpstr[0] == PC[0]){

          if(jack==1){
            //cout << "Chala6";
            tempcover = allif(s, d, pmove, Covermoves,f,j,r,i);   
             set<mov>::const_iterator it;
             for (it = tempcover.begin(); it != tempcover.end(); it++) 
            {
                Covermoves.insert((*it));
            }
            tempcover.clear();
          }

          break;//if our dont append and moves done for this way
        }
        else{ //if enemy append
            //convert file to ascii letters
        string newf(1,char(f+97));
        string newj(1,char(j+97));
        //append to string 
        
        s.erase(s.begin(),s.end());
        s.append(to_string(r));
        s.append(newf);
        d.erase(d.begin(),d.end());
        d.append(to_string(i));
        d.append(newj);
        //add string to struct
        pmove.src = s;
        pmove.dest = d;
        //append move to set
        KMset.insert(pmove);
        break;
       }  
     }
 
  }


  //#7
 i = r;
 j = f;
 for(int temp=0; temp<1; temp++)
 {
   if(i==0 || j==0 || j==1){break;}
   else{i--; j-=2;}

   occ = occupied(i,j,P);

   if (occ!=1){

     KMset = allif(s,d,pmove,KMset,f,j,r,i);

   } 
   else{

     //check if that piece is our or enemy
        occupiedpstr = string(P[i][j]);
        if(occupiedpstr[0] == PC[0]){
          if(jack==1){
            //cout << "Chala7";
            tempcover = allif(s, d, pmove, Covermoves,f,j,r,i);   
             set<mov>::const_iterator it;
             for (it = tempcover.begin(); it != tempcover.end(); it++) 
            {
                Covermoves.insert((*it));
            }
            tempcover.clear();
          }
          break;//if our dont append and moves done for this way
        }
        else{ //if enemy append
            //convert file to ascii letters
        string newf(1,char(f+97));
        string newj(1,char(j+97));
        //append to string 
        
        s.erase(s.begin(),s.end());
        s.append(to_string(r));
        s.append(newf);
        d.erase(d.begin(),d.end());
        d.append(to_string(i));
        d.append(newj);
        //add string to struct
        pmove.src = s;
        pmove.dest = d;
        //append move to set
        KMset.insert(pmove);
        break;
       }  
     }
 
  }

  //#8
 i = r;
 j = f;
 for(int temp=0; temp<1; temp++)
 {
   if(i==0 || i==1 || j==0){break;}
   else{i-=2; j--;}

   occ = occupied(i,j,P);

   if (occ!=1){

     KMset = allif(s,d,pmove,KMset,f,j,r,i);

   } 
   else{

     //check if that piece is our or enemy
        occupiedpstr = string(P[i][j]);
        if(occupiedpstr[0] == PC[0]){
          if(jack==1){
            //cout << "Chala8";
            tempcover = allif(s, d, pmove, Covermoves,f,j,r,i);   
             set<mov>::const_iterator it;
             for (it = tempcover.begin(); it != tempcover.end(); it++) 
            {
                Covermoves.insert((*it));
            }
            tempcover.clear();
          }
          break;//if our dont append and moves done for this way
        }
        else{ //if enemy append
            //convert file to ascii letters
        string newf(1,char(f+97));
        string newj(1,char(j+97));
        //append to string 
        
        s.erase(s.begin(),s.end());
        s.append(to_string(r));
        s.append(newf);
        d.erase(d.begin(),d.end());
        d.append(to_string(i));
        d.append(newj);
        //add string to struct
        pmove.src = s;
        pmove.dest = d;
        //append move to set
        KMset.insert(pmove);
        break;
       }  
     }
 
  }
 
 

 return make_tuple(KMset,Covermoves); 

}

//Pawnmoves
tuple<set<mov>,set<mov>> Pawnmoves(int r, int f, position P, string PC, set<mov>Covermoves, int jack){
  
  set<mov> PMset;
  string occupiedpstr;
  set<mov> tempcover;
  string s;//source
  string d;//dest
  mov pmove;
  int occ = 0;
  int i;
  int j;

  i = r;
  j = f;
  
  //cout << r << f << "yeh dekh\n\n";
  //Pawn is white go up
  if(PC=="W")
  {   
      //#1
      for(int temp=0;temp<1;temp++)
      {
        if(i==7){break;} // this needs an option to change to new piece instead of break
        else{i++;}
      
        occ = occupied(i,j,P);

        if (occ!=1){

        PMset = allif(s,d,pmove,PMset,f,j,r,i);

        }

     }

     //double walk move white
      i = r;
      j = f;
     for(int temp=0;temp<1;temp++)
      {
        if(i!=1){break;} 
        else{i+=2;}
      
        occ = occupied(i,j,P);

        if (occ!=1){

        PMset = allif(s,d,pmove,PMset,f,j,r,i);

        }
      
      }

       i = r;
       j = f;

     //#2 right kill
      for(int temp=0;temp<1;temp++)
      {
        if(i==7){break;} 
        if(j==7){break;}

        else{i++;j++;}
        
        occ = occupied(i,j,P);

        if (occ!=1){

        break;

        } 

        else{

         //check if that piece is our or enemy
        occupiedpstr = string(P[i][j]);
        if(occupiedpstr[0] == PC[0]){

          if(jack==1){
           // cout << "Chala1";
            tempcover = allif(s, d, pmove, Covermoves,f,j,r,i);   
             set<mov>::const_iterator it;
             for (it = tempcover.begin(); it != tempcover.end(); it++) 
            {
                Covermoves.insert((*it));
            }
            tempcover.clear();
          }


          break;//if our dont append and moves done for this way
        }
        else{ //if enemy append
            //convert file to ascii letters
        string newf(1,char(f+97));
        string newj(1,char(j+97));
        //append to string 
        
        s.erase(s.begin(),s.end());
        s.append(to_string(r));
        s.append(newf);
        d.erase(d.begin(),d.end());
        d.append(to_string(i));
        d.append(newj);
        //add string to struct
        pmove.src = s;
        pmove.dest = d;
        //append move to set
        PMset.insert(pmove);
        break;
       }  
     }
   
     }     

    i=r;
    j=f;
    //Left kill
    //#3
    for(int temp=0;temp<1;temp++)
      {
        if(i==7){break;} 
        if(j==0){break;}
        
        else{i++;j--;}
        
        occ = occupied(i,j,P);

        if (occ!=1){

        break;

        } 

        else{

         //check if that piece is our or enemy
        occupiedpstr = string(P[i][j]);
        if(occupiedpstr[0] == PC[0]){

          if(jack==1){
            //cout << "Chala1";
            tempcover = allif(s, d, pmove, Covermoves,f,j,r,i);   
             set<mov>::const_iterator it;
             for (it = tempcover.begin(); it != tempcover.end(); it++) 
            {
                Covermoves.insert((*it));
            }
            tempcover.clear();
          }

          break;//if our dont append and moves done for this way
        }
        else{ //if enemy append
            //convert file to ascii letters
        string newf(1,char(f+97));
        string newj(1,char(j+97));
        //append to string 
        
        s.erase(s.begin(),s.end());
        s.append(to_string(r));
        s.append(newf);
        d.erase(d.begin(),d.end());
        d.append(to_string(i));
        d.append(newj);
        //add string to struct
        pmove.src = s;
        pmove.dest = d;
        //append move to set
        PMset.insert(pmove);
        break;
       }  
     }
   
     }     
      

  
      //spl move 
      
  }
  //Pawn is black go down
  if(PC=="B")
  {
     //#1
      for(int temp=0;temp<1;temp++)
      {
        if(i==0){break;} // this needs an option to change to new piece instead of break

        else{i--;}
      
        occ = occupied(i,j,P);

        if (occ!=1){

        PMset = allif(s,d,pmove,PMset,f,j,r,i);

        }

     }

       //double walk move black
      i = r;
      j = f;
     for(int temp=0;temp<1;temp++)
      {
        if(i!=6){break;} 
        else{i-=2;}
      
        occ = occupied(i,j,P);

        if (occ!=1){

        PMset = allif(s,d,pmove,PMset,f,j,r,i);

        }
      
      }


       i = r;
       j = f;

     //#2 right kill
      for(int temp=0;temp<1;temp++)
      {
        if(i==0){break;} 
        if(j==0){break;} 
        
        else{i--;j--;}
        
        occ = occupied(i,j,P);

        if (occ!=1){

        break;

        } 

        else{

         //check if that piece is our or enemy
        occupiedpstr = string(P[i][j]);
        if(occupiedpstr[0] == PC[0]){

          if(jack==1){
            //cout << "Chala1";
            tempcover = allif(s, d, pmove, Covermoves,f,j,r,i);   
             set<mov>::const_iterator it;
             for (it = tempcover.begin(); it != tempcover.end(); it++) 
            {
                Covermoves.insert((*it));
            }
            tempcover.clear();
          }

          break;//if our dont append and moves done for this way
        }
        else{ //if enemy append
            //convert file to ascii letters
        string newf(1,char(f+97));
        string newj(1,char(j+97));
        //append to string 
        
        s.erase(s.begin(),s.end());
        s.append(to_string(r));
        s.append(newf);
        d.erase(d.begin(),d.end());
        d.append(to_string(i));
        d.append(newj);
        //add string to struct
        pmove.src = s;
        pmove.dest = d;
        //append move to set
        PMset.insert(pmove);
        break;
       }  
     }
   
     }     

    i=r;
    j=f;
    //Left kill
    //#3
    for(int temp=0;temp<1;temp++)
      {
        //cout << i << " " <<j << "\n";
        if(i==0){break;}  
        if(j==7){;break;}
        

        else{i--;j++;}
        //cout << i << " " <<j;
        
        occ = occupied(i,j,P);
        

        if (occ!=1){

        break;

        } 

        else{
          
         //check if that piece is our or enemy
        occupiedpstr = string(P[i][j]);
        if(occupiedpstr[0] == PC[0]){

          if(jack==1){
           // cout << "Chala1";
            tempcover = allif(s, d, pmove, Covermoves,f,j,r,i);   
             set<mov>::const_iterator it;
             for (it = tempcover.begin(); it != tempcover.end(); it++) 
            {
                Covermoves.insert((*it));
            }
            tempcover.clear();
          }

          break;//if our dont append and moves done for this way
        }
        else{ //if enemy append
            //convert file to ascii letters
           
        string newf(1,char(f+97));
        string newj(1,char(j+97));
        //append to string 
        
        s.erase(s.begin(),s.end());
        s.append(to_string(r));
        s.append(newf);
        d.erase(d.begin(),d.end());
        d.append(to_string(i));
        d.append(newj);
        //add string to struct
       // cout << s<<";"<<d;    
        pmove.src = s;
        pmove.dest = d;
        //append move to set
        PMset.insert(pmove);
        break;
       }  
     }
   
     }     
  }

  return make_tuple(PMset,Covermoves);
}

//Kingmoves
tuple<set<mov>,set<mov>> Kingmoves(int r, int f, position P, string PC,set<mov>Covermoves, int jack){

 set<mov> Kset;
 string occupiedpstr;
 set<mov> tempcover;
 string s;//source
 string d;//dest
 mov pmove;
 int occ = 0;
 int i;
 int j;

 //1
    i=r;
    j=f;
    
    for(int temp=0;temp<1;temp++){
      
      //cout << "1st enter";
      //Edge cases
      if(i==7){break;}
      else{i++;}
      if(j==0){break;}
      else{j--;}
      
      occ = occupied(i,j,P);
      //cout<<"occ =" << occ;
      if(occ!=1){

        Kset = allif(s, d, pmove, Kset,f,j,r,i);

      }
      
      else{
        //check if that piece is our or enemy
        occupiedpstr = string(P[i][j]);
        if(occupiedpstr[0] == PC[0]){

          if(jack==1){
            //cout << "Chala1";
            tempcover = allif(s, d, pmove, Covermoves,f,j,r,i);   
             set<mov>::const_iterator it;
             for (it = tempcover.begin(); it != tempcover.end(); it++) 
            {
                Covermoves.insert((*it));
            }
            tempcover.clear();
          }

          break;//if our dont append and moves done for this way
        }
        else{ //if enemy append
            //convert file to ascii letters
        string newf(1,char(f+97));
        string newj(1,char(j+97));
        //append to string 
        
        s.erase(s.begin(),s.end());
        s.append(to_string(r));
        s.append(newf);
        d.erase(d.begin(),d.end());
        d.append(to_string(i));
        d.append(newj);
        //add string to struct
        pmove.src = s;
        pmove.dest = d;
        //append move to set
        Kset.insert(pmove);
        break;
        }
        
       
      }
    }
     //2
     
    i=r;
    j=f;
    for(int temp=0;temp<1;temp++){
      
      //Edge 
      if(i==7){break;}
      else{i++;}
      if(j==7){break;}
      else{j++;}

      occ = occupied(i,j,P);
      if(occ!=1){

        Kset = allif(s, d, pmove, Kset,f,j,r,i);
       

      }
      else{

        //check if that piece is our or enemy
        occupiedpstr = string(P[i][j]);
        if(occupiedpstr[0] == PC[0]){

          if(jack==1){
           // cout << "Chala1";
            tempcover = allif(s, d, pmove, Covermoves,f,j,r,i);   
             set<mov>::const_iterator it;
             for (it = tempcover.begin(); it != tempcover.end(); it++) 
            {
                Covermoves.insert((*it));
            }
            tempcover.clear();
          }

          break;//if our dont append and moves done for this way
        }
        else{ //if enemy append
            //convert file to ascii letters
        string newf(1,char(f+97));
        string newj(1,char(j+97));
        //append to string 
        s.erase(s.begin(),s.end());
        s.append(to_string(r));
        s.append(newf);
        d.erase(d.begin(),d.end());
        d.append(to_string(i));
        d.append(newj);
        //add string to struct
        pmove.src = s;
        pmove.dest = d;
        //append move to set
        Kset.insert(pmove);
        break;
        }
        
        
      }
    }
      

     //3
      i=r;
      j=f;
     for(int temp=0;temp<1;temp++){
      
      //Edge cases
      if(i==0){break;}
      else{i--;}
      if(j==7){break;}
      else{j++;}

      occ = occupied(i,j,P);
      if(occ!=1){
        
        Kset = allif(s, d, pmove, Kset,f,j,r,i);

      }
      else{
        
        //check if that piece is our or enemy
        occupiedpstr = string(P[i][j]);
        if(occupiedpstr[0] == PC[0]){

          if(jack==1){
            //cout << "Chala1";
            tempcover = allif(s, d, pmove, Covermoves,f,j,r,i);   
             set<mov>::const_iterator it;
             for (it = tempcover.begin(); it != tempcover.end(); it++) 
            {
                Covermoves.insert((*it));
            }
            tempcover.clear();
          }

          break;//if our dont append and moves done for this way
        }
        else{ //if enemy append
            //convert file to ascii letters
        string newf(1,char(f+97));
        string newj(1,char(j+97));
        //append to string 
        s.erase(s.begin(),s.end());
        s.append(to_string(r));
        s.append(newf);
        d.erase(d.begin(),d.end());
        d.append(to_string(i));
        d.append(newj);
        //add string to struct
        pmove.src = s;
        pmove.dest = d;
        //append move to set
        Kset.insert(pmove);
        break;
        }
        

      }

    }
     //4
     i=r;
     j=f;
    for(int temp=0;temp<1;temp++){
      
      //Edge cases:1
      if(i==0){break;}
      else{i--;}
      if(j==0){break;}
      else{j--;}
      occ = occupied(i,j,P);
      if(occ!=1){
        
        Kset = allif(s, d, pmove, Kset,f,j,r,i);
        
      }
      else{
        
        //check if that piece is our or enemy
        occupiedpstr = string(P[i][j]);
        if(occupiedpstr[0] == PC[0]){

          if(jack==1){
            //cout << "Chala1";
            tempcover = allif(s, d, pmove, Covermoves,f,j,r,i);   
             set<mov>::const_iterator it;
             for (it = tempcover.begin(); it != tempcover.end(); it++) 
            {
                Covermoves.insert((*it));
            }
            tempcover.clear();
          }

          break;//if our dont append and moves done for this way
        }
        else{ //if enemy append
            //convert file to ascii letters
        string newf(1,char(f+97));
        string newj(1,char(j+97));
        //append to string
        s.erase(s.begin(),s.end());
        s.append(to_string(r));
        s.append(newf);
        d.erase(d.begin(),d.end());
        d.append(to_string(i));
        d.append(newj);
        //add string to struct
        pmove.src = s;
        pmove.dest = d;
        //append move to set
        Kset.insert(pmove);
        break;
        }
        

      }
    }


   //Rook for king
 
 occ = 0;
 //1
    i=r;
    j=f;
    
     for(int temp=0;temp<1;temp++){
      
      //cout << "1st enter";
      //Edge cases
      if(i==0){break;}
      else{i--;}
      
      occ = occupied(i,j,P);
      //cout<<"occ =" << occ;
      if(occ!=1){

        Kset = allif(s, d, pmove, Kset,f,j,r,i);

      }
      
      else{
        //check if that piece is our or enemy
        occupiedpstr = string(P[i][j]);
        if(occupiedpstr[0] == PC[0]){

          if(jack==1){
          //  cout << "Chala1";
            tempcover = allif(s, d, pmove, Covermoves,f,j,r,i);   
             set<mov>::const_iterator it;
             for (it = tempcover.begin(); it != tempcover.end(); it++) 
            {
                Covermoves.insert((*it));
            }
            tempcover.clear();
          }

          break;//if our dont append and moves done for this way
        }
        else{ //if enemy append
            //convert file to ascii letters
        string newf(1,char(f+97));
        string newj(1,char(j+97));
        //append to string 
        
        s.erase(s.begin(),s.end());
        s.append(to_string(r));
        s.append(newf);
        d.erase(d.begin(),d.end());
        d.append(to_string(i));
        d.append(newj);
        //add string to struct
        pmove.src = s;
        pmove.dest = d;
        //append move to set
        Kset.insert(pmove);
        break;
        }
        
       
      }
    }
     //2
     
    i=r;
    j=f;
     for(int temp=0;temp<1;temp++){
      
      //Edge 
      if(i==7){break;}
      else{i++;}
      

      occ = occupied(i,j,P);
      if(occ!=1){

        Kset = allif(s, d, pmove, Kset,f,j,r,i);
       

      }
      else{

        //check if that piece is our or enemy
        occupiedpstr = string(P[i][j]);
        if(occupiedpstr[0] == PC[0]){

          if(jack==1){
            //cout << "Chala1";
            tempcover = allif(s, d, pmove, Covermoves,f,j,r,i);   
             set<mov>::const_iterator it;
             for (it = tempcover.begin(); it != tempcover.end(); it++) 
            {
                Covermoves.insert((*it));
            }
            tempcover.clear();
          }

          break;//if our dont append and moves done for this way
        }
        else{ //if enemy append
            //convert file to ascii letters
        string newf(1,char(f+97));
        string newj(1,char(j+97));
        //append to string 
        s.erase(s.begin(),s.end());
        s.append(to_string(r));
        s.append(newf);
        d.erase(d.begin(),d.end());
        d.append(to_string(i));
        d.append(newj);
        //add string to struct
        pmove.src = s;
        pmove.dest = d;
        //append move to set
        Kset.insert(pmove);
        break;
        }
        
        
      }
    }
      

     //3
      i=r;
      j=f;
     for(int temp=0;temp<1;temp++){
      
      //Edge cases
      if(j==0){break;}
      else{j--;}


      occ = occupied(i,j,P);
      if(occ!=1){
        
        Kset = allif(s, d, pmove, Kset,f,j,r,i);

      }
      else{
        
        //check if that piece is our or enemy
        occupiedpstr = string(P[i][j]);
        if(occupiedpstr[0] == PC[0]){

          if(jack==1){
            //cout << "Chala1";
            tempcover = allif(s, d, pmove, Covermoves,f,j,r,i);   
             set<mov>::const_iterator it;
             for (it = tempcover.begin(); it != tempcover.end(); it++) 
            {
                Covermoves.insert((*it));
            }
            tempcover.clear();
          }

          break;//if our dont append and moves done for this way
        }
        else{ //if enemy append
            //convert file to ascii letters
        string newf(1,char(f+97));
        string newj(1,char(j+97));
        //append to string 
        s.erase(s.begin(),s.end());
        s.append(to_string(r));
        s.append(newf);
        d.erase(d.begin(),d.end());
        d.append(to_string(i));
        d.append(newj);
        //add string to struct
        pmove.src = s;
        pmove.dest = d;
        //append move to set
        Kset.insert(pmove);
        break;
        }
        

      }

    }
     //4
     i=r;
     j=f;
     for(int temp=0;temp<1;temp++){
      
      //Edge cases:1
      if(j==7){break;}
      else{j++;}

      occ = occupied(i,j,P);
      if(occ!=1){
        
        Kset = allif(s, d, pmove, Kset,f,j,r,i);
        
      }
      else{
        
        //check if that piece is our or enemy
        occupiedpstr = string(P[i][j]);
        if(occupiedpstr[0] == PC[0]){

          if(jack==1){
            //cout << "Chala1";
            tempcover = allif(s, d, pmove, Covermoves,f,j,r,i);   
             set<mov>::const_iterator it;
             for (it = tempcover.begin(); it != tempcover.end(); it++) 
            {
                Covermoves.insert((*it));
            }
            tempcover.clear();
          }

          break;//if our dont append and moves done for this way
        }
        else{ //if enemy append
            //convert file to ascii letters
        string newf(1,char(f+97));
        string newj(1,char(j+97));
        //append to string
        
        s.append(to_string(r));
        s.append(newf);
        d.append(to_string(i));
        d.append(newj);
        //add string to struct
        pmove.src = s;
        pmove.dest = d;
        //append move to set
        Kset.insert(pmove);
        break;
        }
        

      }
    } 



 
 return make_tuple(Kset,Covermoves);

}

//hidden king move
int hiddenmove(string osrc, string adest, position P){

    int opr = int(osrc[0])-48;
    int opf = int(osrc[1])-97;
    int kr = int(adest[0])-48;
    int kf = int(adest[1])-97;
    int des =0;
    
    
  //cout << osrc << "--" << adest<< "\n";

  //cout <<"or=" << opr <<"-" <<" of="<< opf << "kr=" << kr << "kf=" << kf <<"\n";
  //cout << P[(int(osrc[0])-48)][(int(osrc[1])-97)][1] << "\n";
  
  if(P[opr][opf][1] == 'Q' ){
    
    //check if in rooks line 
    if((opr-kr)==0 || (opf-kf==0))
    {
      des=1;

    }
    //or if in bishops line
    if( ((opr-kr)*(opr-kr)) == ((opf-kf)*(opf-kf)))
    {
      des=1;
    }

  } 

  if(P[opr][opf][1] == 'r' ){
     
     //check if in rooks line 
    if((opr-kr)==0 || (opf-kf==0))
    {
      des=1;
    }
    
  }

  if(P[opr][opf][1] == 'b' ){

    //if in bishops line
    if( ((opr-kr)*(opr-kr)) == ((opf-kf)*(opf-kf)))
    {
      des=1;
    }

  }
 
  

   return des;
}


//Check_checker function
set<mov> check_check(set<mov> Opponentmoves, set<mov> Appenderset,position P){

 set<mov> Newkingmoves;
 set<mov>::const_iterator oit;
 set<mov>::const_iterator ait;
 set<mov>::const_iterator dait;
 mov kmove;
 int incheck = 0;
 int des;
 string odest;
 string adest;
 string asrc;
 string osrc;

 for (oit = Opponentmoves.begin(); oit != Opponentmoves.end(); oit++){

  for (ait = Appenderset.begin(); ait != Appenderset.end(); ait++)
  {   
        osrc = (*oit).src;
        odest = (*oit).dest; 
        adest = (*ait).dest;
        asrc = (*ait).src; 
        //cout << "asrc=" << asrc << " odest=" <<odest <<"\n\n";

       if(odest == adest)
       {  //cout << "match!\n";
          Appenderset.erase(ait);
       }

       if(asrc == odest){
         
         incheck=1;
         // cout << "King in check" << incheck <<"\n";
         des = hiddenmove(osrc, adest, P);

         //if des ==1 then remove the move else continue;
         //cout << "des is =" <<des << "\n\n";

           if(des==1){
            Appenderset.erase(ait);
          }
       
       }

       else{

          continue;
       }
       
  }

 }

 return Appenderset;
}

//final correction to desired printing 
set<mov> corrector(set<mov> Piecemoves){

 set<mov> CPiecemoves;
 set<mov>::const_iterator fit;
 string s;
 string d;
 string rs,rd;
 int temps;
 int tempd;
 mov fmove;

 for (fit = Piecemoves.begin(); fit != Piecemoves.end(); fit++){
   
   s = (*fit).src;
   d = (*fit).dest;

   //cout << s <<" "<< d <<"\n";

   temps = int(s[0])-48;
   tempd = int(d[0])-48;
   rs = s[1];
   rd = d[1];

   temps++;
   tempd++;

  //cout <<"temps=" <<temps << "\n" <<"tempd=" << tempd <<"\n";

  string ns(1,char(temps)+48);
  string nd(1,char(tempd)+48);
  ns.append(rs);
  nd.append(rd);

  //cout << "ns=" << ns << " nd=" << nd <<"\n"; 

  fmove.src = ns;
  fmove.dest = nd;

  //cout << "fmove.s=" << fmove.src << " fmove.d=" << fmove.dest <<"\n"; 

  CPiecemoves.insert(fmove);

 }


 return CPiecemoves;
}

//The pawn paradox
set<mov> sfkingmoves(set<mov>Appenderset, position P, string doingcol){

    
    int curr;
    int curf;
    int nrank1;
    int nfile1;
    int nrank2;
    int nfile2;

 set<mov>::const_iterator it;
 for (it = Appenderset.begin(); it != Appenderset.end(); it++) {
		 
      //cout << (*it).dest << "\n";
      curr = int((*it).dest[0])-48;
      curf = int((*it).dest[1])-97; 
      //cout << curr <<" - " <<curf <<"\n"; 


      if(doingcol == "W"){

        //cout << "W\n";
        
        //check Left & Right
        nrank1 = curr;
        nfile1 = curf;
        nrank2 = curr;
        nfile2 = curf;
        

        if(curr!=7 && curf!=0){
          
          nrank1++;
          nfile1--;
      
        }
        if(curr!=7 && curf!=7){
          
          nrank2++;
          nfile2++;  

        }
        
       // cout << nrank1 <<" - "<< nfile1 << "\n";
       // cout << nrank2 <<" - "<< nfile2 << "\n\n";
        
        //cout << P[nrank1][nfile1] << "\n";
        if(P[nrank1][nfile1][1]=='p' || P[nrank2][nfile2][1]=='p'){
          
          Appenderset.erase(it);

        }
        else{continue;}
 
        
        
      }

      if(doingcol == "B"){

        //cout << "B\n";
        
        //check Left & Right
        nrank1 = curr;
        nfile1 = curf;
        nrank2 = curr;
        nfile2 = curf;
        
        if(curr!=0 && curf!=7){
          
          nrank1--;
          nfile1++;
      
        }
        if(curr!=0 && curf!=0){
          
          nrank2--;
          nfile2--;  

        }
        
       // cout << nrank1 <<" - "<< nfile1 << "\n";
       // cout << nrank2 <<" - "<< nfile2 << "\n\n";
        
        //cout << P[nrank1][nfile1] << "\n";
        if(P[nrank1][nfile1][1]=='p' || P[nrank2][nfile2][1]=='p'){
          
          Appenderset.erase(it);

        }
        else{continue;}
 
        
        
      }

    
 }

 return Appenderset;
}

//The cover-check removal
set<mov> Cover(set<mov> Totalcovermoves, set<mov> Appenderset){
//Add this here :
  set<mov>::const_iterator km; //kingmoves
  set<mov>::const_iterator tcm; //totalcovermoves

  

  // iterate thru king moves.
  for(km = Appenderset.begin(); km!=Appenderset.end(); km++ ){

    for(tcm = Totalcovermoves.begin(); tcm!=Totalcovermoves.end(); tcm++ )
    // iterate thru Totalcovermoves
    //cout <<"\n" << (*km).dest << "==" << (*tcm).dest <<"\n";
    if((*km).dest == (*tcm).dest)
    {
      //pop that move!!!!!
      //cout << (*km).dest;
      Appenderset.erase(*km);

    }


  }

  
  
  
  //return refined set.
  return Appenderset;

}

// ALL Piece moves functions 
tuple<set<mov>,set<mov>> check_createmoves(string Piecetype,int r,int f,position P,string PC,set<mov> Piecemoves,set<mov> Opponentmoves, string doingcol,set<mov>FM, set<mov>Covermoves, int jack,  set<mov>Totalcovermoves){

  set<mov> Appenderset;
  set<mov> Appenderset2;//for covermoves

  //cout<< "Piecetype is =" << Piecetype << r<<f <<"\n";
  if(Piecetype =="b"){

   string occupiedpstr;
   string s;//source
   string d;//dest
   mov pmove;
   int occ = 0;
   int i;
   int j;

   tie(Appenderset,Appenderset2) = Bishopmoves(r,f,P,PC,Covermoves,jack);
   //insert in main set:
   set<mov>::const_iterator it1;
   for (it1 = Appenderset.begin(); it1 != Appenderset.end(); it1++) {
		 Piecemoves.insert((*it1));
	 }

   for (it1 = Appenderset2.begin(); it1 != Appenderset2.end(); it1++) {
     //cout << (*it1).src << "-" << (*it1).dest ;
		 Totalcovermoves.insert((*it1));
	 }



      
 }

   Appenderset.clear();
   Appenderset2.clear();

 if(Piecetype == "r")
  {
     
   string occupiedpstr;
   string s;//source
   string d;//dest
   mov pmove;
   int occ = 0;
   int i;
   int j;

   tie(Appenderset,Appenderset2) = Rookmoves(r,f,P,PC,Covermoves,jack);
   
   set<mov>::const_iterator it2;
   for (it2 = Appenderset.begin(); it2 != Appenderset.end(); it2++) {
		 Piecemoves.insert((*it2));
	 }
    for (it2 = Appenderset2.begin(); it2 != Appenderset2.end(); it2++) {
     //cout << (*it1).src << "-" << (*it1).dest ;
		 Totalcovermoves.insert((*it2));
	 }
    
  }
  
   Appenderset.clear();
   Appenderset2.clear();

 if(Piecetype == "Q")
 { 
   string occupiedpstr;
   string s;//source
   string d;//dest
   mov pmove;
   int occ = 0;
   int i;
   int j;

   tie(Appenderset,Appenderset2) = Bishopmoves(r,f,P,PC,Covermoves,jack);

  //Append to piecemoves
   set<mov>::const_iterator it3;
   for (it3 = Appenderset.begin(); it3 != Appenderset.end(); it3++) {
		 Piecemoves.insert((*it3));
	 }
   for (it3 = Appenderset2.begin(); it3 != Appenderset2.end(); it3++) {
     //cout << (*it1).src << "-" << (*it1).dest ;
		 Totalcovermoves.insert((*it3));
	 }
   
   Appenderset.clear();
   Appenderset2.clear();

   tie(Appenderset,Appenderset2) = Rookmoves(r,f,P,PC,Covermoves,jack);

   //Append to piecemoves
   set<mov>::const_iterator it4;
   for (it4 = Appenderset.begin(); it4 != Appenderset.end(); it4++) {
		 Piecemoves.insert((*it4));
	 }
   for (it4 = Appenderset2.begin(); it4 != Appenderset2.end(); it4++) {
     //cout << (*it1).src << "-" << (*it1).dest ;
		 Totalcovermoves.insert((*it4));
	 }

   


  }//Queen end

  Appenderset.clear();
  Appenderset2.clear();

  if(Piecetype == "k"){

     tie(Appenderset,Appenderset2) = Knightmoves(r,f,P,PC,Covermoves,jack);
      set<mov>::const_iterator it5;
      for (it5 = Appenderset.begin(); it5 !=Appenderset.end(); it5++) {
		  Piecemoves.insert((*it5));
	 }
    for (it5 = Appenderset2.begin(); it5 != Appenderset2.end(); it5++) {
     //cout << (*it1).src << "-" << (*it1).dest ;
		 Totalcovermoves.insert((*it5));
	 }

  }

  Appenderset.clear();
  Appenderset2.clear();

  if(Piecetype == "p"){

     
     tie(Appenderset,Appenderset2) = Pawnmoves(r,f,P,PC,Covermoves,jack);
     FM = Appenderset;
      
      //set<mov>::const_iterator it100;
      //for (it100 = Appenderset.begin(); it100 !=Appenderset.end(); it100++) {
        //cout << "src=" << (*it100).src << " dest=" << (*it100).dest <<"\n";
		  // }


       set<mov>::const_iterator it6;
      for (it6 = Appenderset.begin(); it6 !=Appenderset.end(); it6++) {
		  Piecemoves.insert((*it6));}

      for (it6 = Appenderset2.begin(); it6 != Appenderset2.end(); it6++) {
     //cout << (*it1).src << "-" << (*it1).dest ;
		 Totalcovermoves.insert((*it6));
	 }

  }

  Appenderset.clear();
  Appenderset2.clear();

  if(Piecetype=="K"){

    tie(Appenderset,Appenderset2) = Kingmoves(r,f,P,PC,Covermoves,jack);

    //Remove the check moves.
    
    if(doingcol==PC){

      Appenderset = check_check(Opponentmoves,Appenderset, P);

      //cout << doingcol;
      Appenderset = sfkingmoves(Appenderset, P, doingcol);

      //cout << "Appendersetsize = "<< Appenderset.size();
      //Function call returns Piecemoves 
      // Parameters Totalcovermoves, Appenderset
      
      Appenderset = Cover(Totalcovermoves,Appenderset);

      //Add this here :
      // iterate thru king moves 
      // iterate thru Totalcovermoves
      // if dest of Kmove == dest of Total cover move
      //pop that move!!!!!
      //return refined set.

      set<mov>::const_iterator it6;
      for (it6 = Appenderset.begin(); it6 !=Appenderset.end(); it6++) {
		  Piecemoves.insert((*it6));}

    
      //Piecemoves = corrector(Piecemoves);
      //cout << Piecemoves.size();


    }
    
    if(doingcol!=PC){

    set<mov>::const_iterator it6;
    for (it6 = Appenderset.begin(); it6 !=Appenderset.end(); it6++) {
		Piecemoves.insert((*it6));}

    for (it6 = Appenderset2.begin(); it6 !=   Appenderset2.end(); it6++){
     //cout << (*it1).src << "-" << (*it1).dest ;
		 Totalcovermoves.insert((*it6));
    }
    }
    
    
    
  }//king end.
 /*
 //Test printer for total cover moves.
  set<mov>::const_iterator adi;
  for(adi= Totalcovermoves.begin(); adi!=Totalcovermoves.end();adi++){

    cout << (*adi).src << "--" << (*adi).dest << "\n\n";

  } 
 */
 return make_tuple(Piecemoves, Totalcovermoves);
}

//main function 
set<mov> legalMoves(position P, string needcolor){

 string newneedcolor;
  
 if(needcolor=="W"){newneedcolor="B";} //newneedcolor is for opponent
 if(needcolor=="B"){newneedcolor="W";}
 string Piecestr; 
 string Piececolor; 
 string Piecetype; 
 set<mov> Piecemoves; //set for the needed moves
 set<mov> Opponentmoves; //for checking check
 set<mov> Covermoves;
 set<mov> Totalcovermoves;
 int jack;
 set<mov> FM;
 int temp; 
 int r; 
 int f; 
 
 

  for(int i=0; i<8; i++){
      for(int j=0; j<8; j++){

          // check occupied
          temp = occupied(i,j,P);
          //cout << i << j << temp  <<"\n" ;
         
          if(temp==1){
            //Disection
            Piecestr = string(P[i][j]);
            Piececolor = Piecestr[0];
            Piecetype = Piecestr[1];
           // r = int(Piecestr[2]) - 48;
           // r--;
            r = i;
            //f = int(Piecestr[3]) - 97 ;
            f = j;
            
           
            //Testing:
           // cout<< Piecestr <<"\n"<< Piececolor <<Piecetype;
           // cout<<"\n" << r << " " << f << "\n";
           // cout << "\n\n\n\n\n\n\n";
            
 //need to check all possible moves first to then compare with king
           // cout<< Piececolor << "=" << needcolor << "\n";
            if (Piececolor == newneedcolor){
              //cout << r << f <<"\n";
              //cout << Piececolor << needcolor << "\n";
              jack =1;
              tie(Piecemoves,Totalcovermoves) = check_createmoves(Piecetype,r,f,P,Piececolor,Piecemoves,Opponentmoves,needcolor,FM,Covermoves,jack,Totalcovermoves);
              //cout << "Done";
            }
           
          }
         
      }
  }

    set<mov>::const_iterator swap;
    for (swap = Piecemoves.begin(); swap != Piecemoves.end(); swap++) {
		 Opponentmoves.insert((*swap));
	 }

    Piecemoves.clear();
          
   
    //self moves
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){

          // check occupied
          temp = occupied(i,j,P);
          //cout << i << j << temp  <<"\n" ;
         
          if(temp==1){
            //Disection
            Piecestr = string(P[i][j]);
            Piececolor = Piecestr[0];
            Piecetype = Piecestr[1];
           // r = int(Piecestr[2]) - 48;
           // r--;
           // f = int(Piecestr[3]) - 97 ;
            r = i;
            f = j;
            
            
            //Testing:
           // cout<< Piecestr <<"\n"<< Piececolor <<Piecetype;
           // cout<<"\n" << r << " " << f << "\n";
            
 //need to check all possible moves first to then compare with king
           // cout<< Piececolor << "=" << needcolor << "\n";
           
            if (Piececolor == needcolor){
              //cout << r << f <<"\n";
              //cout << Piececolor << needcolor;
              jack=0;
              tie(Piecemoves,Totalcovermoves) = check_createmoves(Piecetype,r,f,P,Piececolor,Piecemoves,Opponentmoves,needcolor,FM,Covermoves,jack,Totalcovermoves);
              //cout << "Done";
            }
           
          }
         
      }
  }




   

    //return Opponentmoves;//Testing 
    Piecemoves = corrector(Piecemoves);
    return Piecemoves;
}


/*
int main() {

 row r(8,"e");
 position P(8,r);
 
 //testing please remad

 //P[0][0]="WK"; //WK6f

 P[7][7]="BK"; //BK8h
 P[2][2]="Br"; //Br3c
 P[0][0]="WK"; //WK1a
 P[1][1]="Wp"; //Wp2b
 //P[6][2] = "Bp7c";


 color C;

 
 C.c = "W";
 //end testing

 // -> from here
 set<mov> Finalmoves;


 Finalmoves = legalMoves(P,"W");

 //call printer(Finalmoves) check struct before.
 set<mov>::const_iterator it;

    cout<<"{";
  for (it = Finalmoves.begin(); it != Finalmoves.end(); it++) {

		cout <<"("<< (*it).src <<"," << (*it).dest <<")";
    if(it!= --Finalmoves.end()){cout<<",";}
    else{continue;}

	}

    cout<<"}\n";


}
//-> till here copy to Legal moves.

*/

//compare both the pointers and check why check check isnt working.
