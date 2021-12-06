# Assignment 1 Part B
# Name: Disha Chavan
# Class: TE 10 Batch L 10
# Roll no: 33212
# Problem statement: Write a program to implement an address book with options given below: a) Create address
#		     book. b) View address book. c) Insert a record. d) Delete a record. e) Modify a record. f) Exit

#----------------------------------------------------------------------------------------------------------------------------------------

#! /bin/sh
choice=0 
while [ $choice -lt 6 ] 
do
	echo -e "\n==========================================================================================================="
	echo -e "\nEnter choice\n1.Create address book\n2.View address book\n3.Insert a record\n4.Delete record\n5.Modify record\n6.Exit "
	echo -e "\n==========================================================================================================="
	read choice 
	case $choice in 
		# create book
		1) echo -e "\nEnter name for address book: " 
		   read book 
		   touch $book 
		   echo -e "\nBook created!";;
		# view book
		2) if [ -z "$book" ] 						# validation: if book name not entered
			then 
				echo -e "\nPlease enter book name!" 
				continue
		   else
		   	echo  -e "\n-----------------------------------------------------------------"
		   	echo  -e "\nRoll no\t\tName\t\tAddress\t\tPhone no"
		   	echo  -e "\n-----------------------------------------------------------------"
			cat $book
		   fi ;;
		# Insert in book
		3) if [ -z "$book" ] 						# validation: if book name not entered
			then echo -e "\nPlease enter book name!"
		   else
		   	echo  -e "\nEnter roll no: "
		   	read rollno
			echo  -e "\nEnter name: "
			read name
			echo  -e "\nEnter address: "
			read address
			echo  -e "\nEnter phone no: "
			read phoneno
			echo  -e "$rollno\t\t$name\t\t$address\t\t$phoneno" >> $book 
			sort $book > addressbook 
			mv addressbook $book 
			echo  -e "\nRecord inserted!"
		    fi;;
		# Delete record
		4) if [ -z "$book" ]  						# validation: if book name not entered
			then echo  -e "\nPlease enter book name!"
		   else
			   echo -e "\nEnter roll no to be deleted: "
			   read rollnumber
			   grep $rollnumber $book > record  
			   if [ -z "$record" ]
			   then
				   grep -v $rollnumber $book >> addressbook  
				   rm $book
				   cat addressbook >> $book
				   rm addressbook  
				   echo  -e "\n-----------------------------------------------------------------"
		   		   echo  -e "\nRoll no\tName\tAddress\tPhone no"
		   	           echo  -e "\n-----------------------------------------------------------------"
				   cat $book
			   	   echo  -e "\nRecord deleted!"
			  else
			  	echo  -e "\nRecord not found!" 
			  fi
		   fi;;
		# Modify record
		5) if [ -z "$book" ]  						# validation: if book name not entered
			then echo  -e "\nPlease enter book name!"
		   else
			   echo -e "\nEnter roll no of student to be modified: "
			   read rno 
			   grep $rno $book > record 
			   if [ -z "$record" ]
			   then
				   echo -e "\nRecord is: "
				   cat record
				   grep -v $rno $book >> addressbook  
				   rm $book
				   cat addressbook >> $book
				   rm addressbook  
				   echo -e "\nSelect field to be modified: \n1.Roll No\n2.Name\n3.Address\n4.Phone No "
				   read option
				   case $option in
				   	1) echo -e "\nEnter new number: " 
				   	   read newNo 
				   	   sed -i "s/$rno/$newNo/g" record
				   	   cat record >> $book ;;
				   	2) echo -e "\nEnter name to be modiifed: " 
				   	   read oldName
				   	   echo -e "\nEnter new name: " 
				   	   read newName 			
				   	   sed -i "s/$oldName/$newName/g" record
				   	   cat record >> $book ;;
				       3) echo -e "\nEnter address to be modiifed: " 
				   	   read oldName
				   	   echo -e "\nEnter new address: " 
				   	   read newName 				   	
				   	   sed -i "s/$oldName/$newName/g" record
				   	   cat record >> $book ;;
				       4) echo -e "\nEnter phone no to be modiifed: " 
				   	   read oldName
				   	   echo -e "\nEnter new number: " 
				   	   read newName 				 	
				   	   sed -i "s/$oldName/$newName/g" record
				   	   cat record >> $book ;;
				   
				   esac 
			  else
			  	echo -e "\nRecord not found!"
			  fi
		    fi ;;
		  6) echo -e "\nThankyou!!"
		   
		
	esac
done