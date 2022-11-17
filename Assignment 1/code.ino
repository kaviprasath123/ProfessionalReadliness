int x,y,t ;
void setup ()
{
  pinMode( 8, INPUT);
  pinMode( 2, OUTPUT);
  pinMode( 5, OUTPUT);
  pinMode( A5, INPUT);
  pinMode( A4, INPUT);
  Serial.begin(9600);
}
void loop ()
{
  x= digitalRead(8);
  y= analogRead(A5);
  t= analogRead(A4);
  t= (t*5)/1.024;
  t= t/10;
  Serial.print("Temperature:  ");
  Serial.println(t);
  Serial.print("Human detected (1:yes, 0:no):  ");
  Serial.println(x);
  Serial.print("milivolt through LDR:  ");
  Serial.println(y);
  
  if (x<1)
  {
    digitalWrite(5,0);
    digitalWrite(2,0);
    
  }
  else
  {
    if ((y<550) && (t>32))
    {
      {digitalWrite(5,1);
       digitalWrite(2,1);}
      delay(4000);
      
    }
    
    else
    {
     	 if ((y>550) && (t>32))
    	{
           {digitalWrite(5,0);
            digitalWrite(2,1);}
           delay(4000);
           
    	}
    	
      		else
    		{
      			if ((y<550) && (t<32))
    			{
                  {digitalWrite(5,1);
                   digitalWrite(2,0);}
                  delay(4000);
                  
    			}
    				
        			else
        			{
                      {digitalWrite(5,0);
                       digitalWrite(2,0);}
                      delay(1000);
        			}
            }
    }
  }
}
