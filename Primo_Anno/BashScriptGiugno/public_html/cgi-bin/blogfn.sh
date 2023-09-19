#!/bin/bash
## ==========================================
## SUPSI - Ambienti Operativi - BashBLOG
## Amos Brocco, Vanni Galli
## ========================================== 

# Struttura della directory (sotto-directory di BASHBLOG_DIR)
# posts/
#       YYYY-MM-DD-HH-MM-SS.SSS/         (identificatore)
#                               title    (titolo)
#                               author   (autore)
#                               content  (contenuto)
#								tags/
#									tag1 (file vuoto)
#									tag2 (file vuoto)

BASHBLOG_DIR=..

function exists_post() {
	# TODO: Ritorna vero se il post X esiste
	# $1 è l'identificatore del post X
	
	echo "Implementa ${FUNCNAME[0]}"
}

function get_all_post_ids() {
	# TODO: Ritorna la lista di tutti i post (identificatori)
	
	echo "Implementa ${FUNCNAME[0]}"
}

function get_all_authors() {
	# TODO: Ritorna la lista di tutti gli autori
	
	echo "Implementa ${FUNCNAME[0]}"
}

function get_all_tags() {
	# TODO: Ritorna la lista di tutti i tag
	
	echo "Implementa ${FUNCNAME[0]}"
}

function get_all_posts_with_tag() {
	# TODO: Ritorna la lista di tutti i post classificati con il tag X
	# $1 è il tag X
	
	echo "Implementa ${FUNCNAME[0]}"
}

function get_all_posts_from_author() {
	# TODO: Ritorna la lista di tutti i post di un autore
	# $1 è il nome dell'autore
	
	echo "Implementa ${FUNCNAME[0]}"
}

function get_post_content() {
	# TODO: Ritorna il contenuto di un post
	# $1 è l'identificatore del post
	
	echo "Implementa ${FUNCNAME[0]}"
}

function get_post_author() {
	# TODO: Ritorna l'autore di un post
	# $1 è l'identificatore del post
	
	echo "Implementa ${FUNCNAME[0]}"
}

function get_post_title() {
	# TODO: Ritorna il titolo di un post
	# $1 è l'identificatore del post
	
	echo "Implementa ${FUNCNAME[0]}"
}

function get_post_tags() {
	# TODO: Ritorna la lista dei tag di un post
	# $1 è l'identificatore del post
	
	echo "Implementa ${FUNCNAME[0]}"
}

function set_post_content() {
	# $1 è l'identificatore del post
	# Il contenuto è letto dallo standard input
	
	echo "Implementa ${FUNCNAME[0]}"
}

function set_post_author() {
	# TODO: Definisce l'autore di un post
	# $1 è l'identificatore del post
	# $2 è l'autore del post
	
	echo "Implementa ${FUNCNAME[0]}"
}

function set_post_title() {
	# TODO: Definisce il titolo di un post
	# $1 è l'identificatore del post
	# $2 è il titolo
	
	echo "Implementa ${FUNCNAME[0]}"
}

function add_tag() {
	# TODO: Aggiunge un tag a un post
	# $1 è l'identificatore del post
	# $2 è il tag da aggiungere
	
	echo "Implementa ${FUNCNAME[0]}"
}

function remove_tag() {
	# TODO: Cancella un tag di un post
	# $1 è l'identificatore del post
	# $2 è il tag da cancellare
	
	echo "Implementa ${FUNCNAME[0]}"
}

function clear_tags() {
	# TODO: Cancella tutti i tag di un post
	# $1 è l'identificatore del post
	

	echo "Implementa ${FUNCNAME[0]}"
}

function create_post() {
	# TODO: crea un nuovo post (vuoto) e ritorna l'identificatore
	
	echo "Implementa ${FUNCNAME[0]}"
}

function get_post_date() {
	# TODO: Ritorna la data (formattata) del post
	# $1 è l'identificatore del post
	
	echo "Implementa ${FUNCNAME[0]}"
}

function delete_post() {
	# TODO: Cancella un post
	# $1 è l'identificatore del post
	
	echo "Implementa ${FUNCNAME[0]}"
}

function get_n_most_used_tags() {
	# TODO: Ritorna gli N tag più usati
	# $1 è il numero N di tag
	
	echo "Implementa ${FUNCNAME[0]}"
}

function get_n_most_recent_posts() {
	# TODO: Ritorna gli N post più recenti
	# $1 è il numero N di post
	
	echo "Implementa ${FUNCNAME[0]}"
}

function get_posts_containing_content() {
	# TODO: Ritorna gli identificatori dei post il cui testo contiene 
	#       il termine X
	# $1 è il termine X
	
	echo "Implementa ${FUNCNAME[0]}"
}

function get_posts_containing_title() {
	# TODO: Ritorna gli identificatori dei post il cui titolo contiene 
	#       il termine X
	# $1 è il termine X
	
	echo "Implementa ${FUNCNAME[0]}"
}

function generate_sample_blog_content() {
	# TODO: Genera del contenuto di esempio per il blog
	
	echo "Implementa ${FUNCNAME[0]}"
}


