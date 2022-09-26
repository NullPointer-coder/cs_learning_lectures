
import java.awt.GridLayout;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import java.awt.*;

public class LayoutExample {


	public void gridlayoutExample() {

		JFrame f = new JFrame();
		
		JButton b1 = new JButton("1");
		JButton b2 = new JButton("2");
		JButton b3 = new JButton("3");
		JButton b4 = new JButton("4");
		JButton b5 = new JButton("5");
		JButton b6 = new JButton("6");
		JButton b7 = new JButton("7");
		JButton b8 = new JButton("8");
		JButton b9 = new JButton("9");
		// adding buttons to the frame

		
		f.add(b1);
		f.add(b2);
		f.add(b3);
		f.add(b4);
		f.add(b5);
		f.add(b6);
		f.add(b7);
		f.add(b8);
		f.add(b9);

		// setting grid layout of 3 rows and 3 columns
		//f.setLayout(new GridLayout(3, 3, 20, 25));    
		// f.setLayout(new GridLayout(3, 3));
		f.setLayout(new GridLayout(3, 3));
		f.setSize(300, 300);
		f.setVisible(true);
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
	
	
	
	
		public void borderlayoutExample() {
			
			JFrame f = new JFrame();
			
			JButton b1 = new JButton("Button North");
			JButton b2 = new JButton("Button West");
			JButton b3 = new JButton("Button Center");
			JButton b4 = new JButton("Button East");
			JButton b5 = new JButton("Button South");
			// adding buttons to the frame
			// setting grid layout of 3 rows and 3 columns
			f.setLayout(new BorderLayout());
			
			
			f.add(b1, BorderLayout.NORTH);
			f.add(b2, BorderLayout.WEST);
			f.add(b3, BorderLayout.CENTER);
			f.add(b4, BorderLayout.EAST);
			f.add(b5, BorderLayout.SOUTH);
			
			f.setSize(640, 240);
			f.setVisible(true);
			f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		}
	
	
	public void flowlayoutExample() {
		
		JFrame f = new JFrame();
		
		JButton b1 = new JButton("Button North");
		JButton b2 = new JButton("Button West");
		JButton b3 = new JButton("Button Center");
		JButton b4 = new JButton("Button East");
		JButton b5 = new JButton("Button South");
		// adding buttons to the frame
		// setting grid layout of 3 rows and 3 columns
		f.setLayout(new FlowLayout());
		
		
		f.add(b1);
		f.add(b2);
		f.add(b3);
		f.add(b4);
		f.add(b5);
		
		f.setSize(640, 140);
		f.setVisible(true);
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
	
	

	public static void main(String[] args) {

		LayoutExample eWindow = new LayoutExample();
		eWindow.gridlayoutExample();
		eWindow.borderlayoutExample();
		
		eWindow.flowlayoutExample();
	}

}
