#define _CONTACT_H_

typedef struct contact{
    char *nom;
    char *prénom;
};

typedef struct TIME {
    int heure;
    int minute;
};

typedef struct DATE{
    int jour;
    int mois;
    int année;
};

typedef struct info_rdv{
    struct DATE *date;
    struct TIME *heure;
    struct TIME *durée;
    char *objet;
};

typedef struct liste_rdv{
    struct info_rdv *rdv;
    struct liste_rdv *suivant;
};

char *scanString();