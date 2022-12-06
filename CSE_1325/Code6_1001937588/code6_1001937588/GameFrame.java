/**
Name: Hasnain Bharmal
ID:1001937588
 */

package code6_1001937588;

import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Random;

import javax.swing.Icon;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JTextField;
import javax.swing.SwingConstants;

public class GameFrame extends JFrame 
{
    private JLabel label1;
    private JButton OKButton;
    private JButton CancelButton;
    private JTextField textField1;
    private String CCName;

    public GameFrame() 
    {
        super("Welcome to my guessing game");
        setLayout(new FlowLayout());
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        Random rn = new Random();
        int r_num = rn.nextInt(4) + 1;

        switch (r_num) 
        {
            case 1:
                CCName = "peter";
                break;
            case 2:
                CCName = "mrbean";
                break;
            case 3:
                CCName = "minions";
                break;
            case 4:
                CCName = "spongebob";
                break;
        }
        Icon CC = new ImageIcon(getClass().getResource(CCName + ".gif"));
        label1 = new JLabel();
        label1.setText("What is the Cartoons Character Name?");
        label1.setIcon(CC);
        label1.setHorizontalTextPosition(SwingConstants.CENTER);
        label1.setVerticalTextPosition(SwingConstants.BOTTOM);
        label1.setToolTipText("Hint");
        add(label1);

        EventHandler handler = new EventHandler();
        textField1 = new JTextField("Enter your text here",30);
        textField1.selectAll();
        textField1.addActionListener(handler);
        add(textField1);

        OKButton = new JButton();
        OKButton.setText("OK");
        OKButton.addActionListener(handler);
        add(OKButton);

        CancelButton = new JButton();
        CancelButton.setText("Cancel");
        CancelButton.addActionListener(handler);
        add(CancelButton);

    }

    private class EventHandler implements ActionListener 
    {
        @Override
        public void actionPerformed(ActionEvent event) 
        {
            String msg = "";
            Boolean correct = false;

            if (CCName.equalsIgnoreCase(textField1.getText())) 
            {
                msg = "Correct";
                correct = true;
            } else 
            {
                msg = "Invalid name";
            }
            if (event.getSource() == OKButton || event.getSource() == textField1) 
            {
                JOptionPane.showMessageDialog(null, msg);
                if (correct) 
                {
                    System.exit(0);
                } 
            }
            else if(event.getSource() == CancelButton) 
            {
                System.exit(0);
            }
        }
    }
}
