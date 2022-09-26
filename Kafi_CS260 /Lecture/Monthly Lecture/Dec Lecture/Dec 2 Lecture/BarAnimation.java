
import java.awt.GridLayout;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import java.awt.KeyboardFocusManager;
import javax.swing.JTextField;
import javax.swing.JLabel;
import java.awt.*;
import java.awt.event.*;
import java.awt.*; 
import java.awt.event.*; 
import javax.swing.*;

public class BarAnimation extends JPanel implements ActionListener{
	private Point p1; // location of first rectangle 
	private Point p2; // location of second rectangle 
	private int dx; // amount by which to move horizontally 
	private int dy; // amount by which to move vertically
	
public BarAnimation(){
	p1 = new Point(20, 40); 
	p2 = new Point(60, 10);
	
	dx = dy = 5;
	// set up timer to animate rectangles every 100 ms
	Timer time = new Timer(100, this);
	time.start();
}
	// draws two rectangles on this panel on the screen
	public void paintComponent(Graphics g) {
	
	super.paintComponent(g); // call JPanel's version
	g.setColor(Color.RED); 
	g.fillRect(p1.x, p1.y, 70, 30); 
	g.setColor(Color.BLUE); 
	g.fillRect(p2.x, p2.y, 20, 80);
	}
	
// Handles clicks on Compute button by computing the BMI. 
public void actionPerformed(ActionEvent event) {
	p1.x += dx;
	p2.y += dy;
	if (p1.x <= 0 || p1.x + 70 >= getWidth()) {
		dx = - dx; // rectangle 1 has hit left/right edge 
	}
	if (p2.y <= 0 || p2.y + 80 >= getHeight()) {
		dy = - dy; // rectangle 2 has hit top/bottom edge
	}
	repaint();
}

	public static void main(String[] args) {
		BarAnimation gPanel = new BarAnimation();
		JFrame frame = new JFrame("Animating Bars");
		frame.add(gPanel);
		frame.setSize(320, 240);
		//frame.pack();
		frame.setVisible(true);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}

}
	