
	var sp1=0,sp2=0;
	var rp1=false,rp2=false;
	var compv=false;
	var playwithcomp=false;
	function oppo()
	{
		document.getElementById("card").style.visibility="visible";
		document.getElementById("op1").style.visibility="hidden";
		document.getElementById("op2").style.visibility="hidden";	
	}
	function comp()
	{
		playwithcomp=true;
		document.getElementById("card").style.visibility="visible";
		document.getElementById("op1").style.visibility="hidden";
		document.getElementById("op2").style.visibility="hidden";
	}
	function clear()
	{
		var i=1;
		for (i=1;i<=100;i++)
		{
			var strs="b"+i;
			if(strs=="b"+sp1 || strs== "b"+sp2)
			{
				// nothing!! Don't remove color on score boxes
			}
			else
			{
				// remove color on other boxes
				document.getElementById(strs).style.backgroundColor="white";
			}
		}
	}
	function ladders(arg,score)
	{
		if(arg=="l1")
		{
			if(score==11) { sp1 = 42; clear(); document.getElementById("b"+sp1).style.backgroundColor="cyan"; }
			if(score==28) { sp1 = 84; clear(); document.getElementById("b"+sp1).style.backgroundColor="cyan"; }
			if(score==35) { sp1 = 57; clear(); document.getElementById("b"+sp1).style.backgroundColor="cyan"; }
			if(score==40) { sp1 = 78; clear(); document.getElementById("b"+sp1).style.backgroundColor="cyan"; }
			if(score==53) { sp1 = 88; clear(); document.getElementById("b"+sp1).style.backgroundColor="cyan"; }
			if(score==58) { sp1 = 85; clear(); document.getElementById("b"+sp1).style.backgroundColor="cyan"; }
			if(score==11 || score==28 || score==35 || score==40 || score==53 || score==58)
			{
				document.getElementById("lad1").innerHTML="Got a ladder at "+score;
			}
			else
			{
				document.getElementById("lad1").innerHTML="";	
			}
		}
		else if(arg=="l2")
		{
			if(score==11) { sp2 = 42; clear(); document.getElementById("b"+sp2).style.backgroundColor="yellow"; }
			if(score==28) { sp2 = 84; clear(); document.getElementById("b"+sp2).style.backgroundColor="yellow"; }
			if(score==35) { sp2 = 57; clear(); document.getElementById("b"+sp2).style.backgroundColor="yellow"; }
			if(score==40) { sp2 = 78; clear(); document.getElementById("b"+sp2).style.backgroundColor="yellow"; }
			if(score==53) { sp2 = 88; clear(); document.getElementById("b"+sp2).style.backgroundColor="yellow"; }
			if(score==58) { sp2 = 85; clear(); document.getElementById("b"+sp2).style.backgroundColor="yellow"; }
			if(score==11 || score==28 || score==35 || score==40 || score==53 || score==58)
			{
				document.getElementById("lad2").innerHTML="Got a ladder at "+score;
			}
			else
			{
				document.getElementById("lad2").innerHTML="";	
			}
		}
	}
	function snakes(arg,score)
	{
		if(arg=="l1")
		{
			if(score==96) { sp1 = 51; clear(); document.getElementById("b"+sp1).style.backgroundColor="cyan"; }
			if(score==92) { sp1 = 47; clear(); document.getElementById("b"+sp1).style.backgroundColor="cyan"; }
			if(score==79) { sp1 = 39; clear(); document.getElementById("b"+sp1).style.backgroundColor="cyan"; }
			if(score==64) { sp1 = 36; clear(); document.getElementById("b"+sp1).style.backgroundColor="cyan"; }
			if(score==44) { sp1 = 17; clear(); document.getElementById("b"+sp1).style.backgroundColor="cyan"; }
			if(score==27) { sp1 = 10; clear(); document.getElementById("b"+sp1).style.backgroundColor="cyan"; }
			if(score==96 || score==92 || score==79 || score==64 || score==44 || score==27)
			{
				document.getElementById("snk1").innerHTML="Caught by snake at "+score;
			}
			else
			{
				document.getElementById("snk1").innerHTML="";
			}
		}
		else if(arg=="l2")
		{
			if(score==96) { sp2 = 51; clear(); document.getElementById("b"+sp2).style.backgroundColor="yellow"; }
			if(score==92) { sp2 = 47; clear(); document.getElementById("b"+sp2).style.backgroundColor="yellow"; }
			if(score==79) { sp2 = 39; clear(); document.getElementById("b"+sp2).style.backgroundColor="yellow"; }
			if(score==64) { sp2 = 36; clear(); document.getElementById("b"+sp2).style.backgroundColor="yellow"; }
			if(score==44) { sp2 = 17; clear(); document.getElementById("b"+sp2).style.backgroundColor="yellow"; }
			if(score==27) { sp2 = 10; clear(); document.getElementById("b"+sp2).style.backgroundColor="yellow"; }
			if(score==96 || score==92 || score==79 || score==64 || score==44 || score==27)
			{
				document.getElementById("snk2").innerHTML="Caught by snake at "+score;
			}
			else
			{
				document.getElementById("snk2").innerHTML="";
			}
		}	
	}
	function move(arg,score)
	{
		clear();
		if(arg=="l1")
		{
			var strs="b"+score;
			document.getElementById(strs).style.backgroundColor="cyan";
			ladders(arg,score);
			snakes(arg,score);
		}
		else if(arg=="l2")
		{
			var strs="b"+score;
			document.getElementById(strs).style.backgroundColor="yellow";
			ladders(arg,score);
			snakes(arg,score);
		}
	}
	function roll(arg)
	{
		var gen=Math.floor((Math.random()*6)+1);
		document.getElementById(arg).innerHTML="Number got : "+gen;
		if(arg=="l1")
		{	
			document.getElementById("turn").innerHTML="Turn of Player2";
			if(rp1==false)
			{
				if(gen==6)
				{
					rp1=true;
					document.getElementById("rs1").innerHTML="Released";
				}
			}
			else
			{
				if(sp1+gen>100)
				{
					// cannot increment score > 100
				}
				else if(sp1+gen==100)
				{
					var win1=1;
					sp1=sp1+gen;
					move(arg,sp1);
					document.getElementById("cp1").innerHTML="Position : "+sp1;	
				}
				else
				{
					sp1=sp1+gen;
					move(arg,sp1);
					document.getElementById("cp1").innerHTML="Position : "+sp1;					
				}
			}
			if(gen!=6)
			{
				document.getElementById("p1").style.visibility="hidden";
				document.getElementById("p2").style.visibility="visible";
				document.getElementById("l1").style.visibility="visible";
				if(playwithcomp==false) 
				{ 
					document.getElementById("l2").style.visibility="hidden";
				}
				else 
				{ 
					document.getElementById("l2").style.visibility="visible";
					document.getElementById("p2").style.visibility="hidden"; 
				}
				if(playwithcomp==true)
				{
					if(win1!=1) { window.setTimeout(playComp,1500); }
					document.getElementById("turn").innerHTML="Turn of Computer";
				}
			}
			else
			{
				document.getElementById("turn").innerHTML="Turn of Player1";
				document.getElementById("p2").style.visibility="hidden";
				document.getElementById("p1").style.visibility="visible";
				document.getElementById("l2").style.visibility="visible";
				document.getElementById("l1").style.visibility="visible";
			}
			if(win1==1)
			{
				callOff("w1");
			}
		}
		else if(arg=="l2")
		{
			document.getElementById("turn").innerHTML="Turn of Player1";
			if(rp2==false)
			{
				if(gen==6)
				{
					rp2=true;
					document.getElementById("rs2").innerHTML="Released";
				}
			}
			else
			{
				if(sp2+gen>100)
				{
					// cannot increment score > 100
				}
				else if(sp2+gen==100)
				{
					var win2=1;
					sp2=sp2+gen;
					move(arg,sp2);
					document.getElementById("cp2").innerHTML="Position : "+sp2;
				}
				else
				{
					sp2=sp2+gen;
					move(arg,sp2);
					document.getElementById("cp2").innerHTML="Position : "+sp2;
				}
			}
			if(gen!=6)
			{
				document.getElementById("p2").style.visibility="hidden";
				document.getElementById("p1").style.visibility="visible";
				document.getElementById("l2").style.visibility="visible";
				document.getElementById("l1").style.visibility="hidden";
			}
			else
			{
				document.getElementById("turn").innerHTML="Turn of Player2";
				document.getElementById("p1").style.visibility="hidden";
				document.getElementById("p2").style.visibility="visible";
				document.getElementById("l1").style.visibility="visible";
				document.getElementById("l2").style.visibility="visible";
			}
			if(win2==1)
			{
				callOff("w2");
			}
		}
	}
	function playComp()
	{
		var gen=Math.floor((Math.random()*6)+1);
		document.getElementById("l2").innerHTML="Number got : "+gen;
		document.getElementById("l2").style.visibility="visible";
		document.getElementById("p2").style.visibility="hidden";
		var arg="l2";
		if(compv==false)
		{
			if(gen==6)
			{
				compv=true;
				document.getElementById("rs2").innerHTML="Released";
			}
		}
		else
		{
			if(sp2+gen>100)
			{
				// no score increment
			}
			else if(sp2+gen==100)
			{
				var win2=1;
				sp2=sp2+gen;
				move(arg,sp2);
				document.getElementById("cp2").innerHTML="Position : "+sp2;
			}
			else
			{
				sp2=sp2+gen;
				move(arg,sp2);
				document.getElementById("cp2").innerHTML="Position : "+sp2;
			}	
		}
		if(gen!=6)
		{
			document.getElementById("p1").style.visibility="visible";
			document.getElementById("l1").style.visibility="hidden";
		}
		else
		{
			document.getElementById("p1").style.visibility="visible";
			document.getElementById("l1").style.visibility="hidden";
		}
		document.getElementById("turn").innerHTML="Turn of Player1";
		if(win2==1)
		{
			callOff("comp");
		}
	}
	function callOff(play)
	{
		document.getElementById("p1").style.visibility="hidden";
		document.getElementById("p2").style.visibility="hidden";
		if(play=="w1")
		{
			document.getElementById("turn").innerHTML="Winner is Player 1";
		}
		if(play=="w2")
		{
			document.getElementById("turn").innerHTML="Winner is Player 2";
		}
		else if(play=="comp")
		{
			document.getElementById("turn").innerHTML="Winner is Computer";
		}
	}
