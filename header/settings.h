#ifndef SETTINGS_H
#define SETTINGS_H

typedef struct {

    int max_n_players;
    int n_decks;

} Settings;

void init_settings(Settings* settings);

#endif