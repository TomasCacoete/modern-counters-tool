typedef struct {
    
    int max_n_players;
    int n_decks;

} Settings;

void init_settings(Settings* settings){ //TODO: Read file and get settings
    settings->max_n_players = 7;
    settings->n_decks = 1;
}