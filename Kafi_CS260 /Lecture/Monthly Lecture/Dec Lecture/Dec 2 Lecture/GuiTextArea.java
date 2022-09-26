
import java.awt.GridLayout;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.JLabel;
import javax.swing.JTextArea;
import javax.swing.JScrollPane;
import java.awt.*;
import java.awt.event.*;

public class GuiTextArea implements ActionListener{
	
JTextArea linesOfText;
JButton computeButton;
JFrame frame; 
JLabel bmiLabel;
public GuiTextArea(){
	
	linesOfText = new JTextArea(5, 20);
	linesOfText.setFont(new Font("Serif", Font.ITALIC, 16));
	// overall frame 
	frame = new JFrame("GuiTextArea"); 
	frame.setLayout(new GridLayout(1, 1)); 
	
	
	frame.add(new JScrollPane(linesOfText));
	frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); 
	frame.pack(); 
	frame.setVisible(true); 
	
}
	
	
	// Handles clicks on Compute button by computing the BMI. 
	public void actionPerformed(ActionEvent event) {
	
		
	
	}

	public static void main(String[] args) {

		GuiTextArea gWindow = new GuiTextArea();
	}

}
	