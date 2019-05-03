static gboolean
button_press_callback (GtkWidget      *event_box,
                       GdkEventButton *event,
                       gpointer        data)
{
  g_print ("Event box clicked at coordinates %f,%f\n",
           event->x, event->y);

  // Returning TRUE means we handled the event, so the signal
  // emission should be stopped (don’t call any further callbacks
  // that may be connected). Return FALSE to continue invoking callbacks.
  return TRUE;
}

static GtkWidget*
create_image (void)
{
  GtkWidget *image;
  GtkWidget *event_box;

  image = gtk_image_new_from_file ("myfile.png");

  event_box = gtk_event_box_new ();

  gtk_container_add (GTK_CONTAINER (event_box), image);

  g_signal_connect (G_OBJECT (event_box),
                    "button_press_event",
                    G_CALLBACK (button_press_callback),
                    image);

  return image;
}