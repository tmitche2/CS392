#include <gtk/gtk.h>
#include <string.h>
#include <math.h>

GtkWidget *window;
GtkWidget *button;
GtkWidget *halign;
GtkWidget *image;
//GtkWidget *tails;
//GtkWidget *tails;
GtkWidget *box;
GtkWidget *label;
image = gtk_image_new_from_file("tails.png");

void print_msg(GtkWidget *widget, gpointer window){
	int r = rand();
	if(r % 2 == 0){
		printf("Tails\n");
	}
	else{
		printf("Fuck you its heads\n");
	}
}

void button_press_callback(GtkWidget *box, GdkEventButton *event, gpointer data){
	int x = rand();
	if(x % 2 == 0){
		image = gtk_image_new_from_file("heads.png");
		printf("heads\n");
		//gtk_container_remove(GTK_CONTAINER(box), heads);
		//gtk_container_add(GTK_CONTAINER(box), heads);
	}
	else{
		image = gtk_image_new_from_file("tails.png");
		printf("tail\n");

		//gtk_container_remove(GTK_CONTAINER(box), tails);
		//gtk_container_add(GTK_CONTAINER(box), tails);
	}

}

int main(int argc, char *argv[]){
	gtk_init(&argc, &argv);
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_default_size(GTK_WINDOW(window), 500, 500);
	button = gtk_button_new_with_label("Click Here");
	g_signal_connect(button, "clicked", G_CALLBACK(print_msg), NULL);
	label = gtk_label_text();
	//tails = gtk_image_new_from_file("tails.png");
	box = gtk_event_box_new();

	gtk_container_add(GTK_CONTAINER(box), image);
	//gtk_container_add(GTK_CONTAINER(box), tails);

	halign = gtk_alignment_new(0,0,0,0);
	//gtk_container_add(GTK_CONTAINER(halign), button);
	gtk_container_add(GTK_CONTAINER(window), halign);
	gtk_container_add(GTK_CONTAINER(halign), box);


	gtk_widget_show_all(window);
	g_signal_connect(G_OBJECT(box), "button_press_event", G_CALLBACK(button_press_callback), image);
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

	gtk_main();

	return 0;

}