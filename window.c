#include <gtk/gtk.h>

#define BOARD_WIDTH 8
#define BOARD_HEIGHT 8

int main(int argc, char *argv[]) {
	GtkWidget *window;
	GtkWidget *grid;

	gtk_init(&argc, &argv);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	g_signal_connect(G_OBJECT(window), "delete-event", G_CALLBACK(gtk_main_quit), NULL);
	
	grid = gtk_grid_new();

	for (int r = 0; r < BOARD_HEIGHT; ++r) {
		for (int c = 0; c < BOARD_WIDTH; ++c) {
			GtkWidget *button;
			button = gtk_button_new();
			gtk_grid_attach(GTK_GRID(grid), button, c, r, 1, 1);
		}
	}

	gtk_container_add(GTK_CONTAINER(window), grid);	
	gtk_widget_show_all(GTK_WIDGET(window));
	gtk_main();
	
	return 0;
}
