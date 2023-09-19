#!/bin/bash
## ==========================================
## SUPSI - Ambienti Operativi - BashBLOG
## Amos Brocco, Vanni Galli
## ========================================== 
. parameters.sh
. blogfn.sh

## ==========================================
## Parsing dei tag più usati
## ========================================== 
MOST_USED_TAGS=""
for tag in $(get_n_most_used_tags 10); do
	MOST_USED_TAGS="<a class=\"p-2\" href=\"lookup.sh?tag=$tag\">#$tag</a> $MOST_USED_TAGS"
done

## ==========================================
## Determina azione utente
## ========================================== 
if [ "${parameters['action']}" == "update" ]; then
	POST_ID=${parameters["pid"]}
	if [ -z "$POST_ID" ]; then
		exit 1
	fi
	set_post_title "$POST_ID" "${parameters["title"]}"
	set_post_author "$POST_ID" "${parameters["author"]}"
	set_post_content "$POST_ID" "${parameters["content"]}"
	clear_tags "$POST_ID"
	for tag in $(echo "${parameters["tags"]}"); do
		add_tag "$POST_ID" "$tag"					
	done
	echo "${parameters["content"]}" | set_post_content "$POST_ID"
elif [ "${parameters['action']}" == "create" ]; then
	POST_ID=$(create_post)
elif [ "${parameters['action']}" == "delete" ]; then
	POST_ID=${parameters["pid"]}
	delete_post "$POST_ID"
	echo "Location: index.sh"
	echo ""
	exit 0
else
	POST_ID=${parameters["pid"]}
fi

POST_TITLE=$(get_post_title "$POST_ID")
POST_AUTHOR=$(get_post_author "$POST_ID")
POST_DATE=$(get_post_date "$POST_ID")
POST_CONTENT=$(get_post_content "$POST_ID")
POST_TAGS=""
for tag in $(get_post_tags $POST_ID); do
	POST_TAGS="$tag $POST_TAGS"
done

## ==========================================
## Contenuto pagina
## ========================================== 
cat << EOF
Content-type: text/html

<!doctype html>
<html lang="en">
<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
    <meta name="description" content="">
    <meta name="author" content="">
    <title>Ambienti Operativi 2019 - Blog Template</title>
    <link href="../css/bootstrap.min.css" rel="stylesheet">
    <link href="../css/blog.css" rel="stylesheet">
    <link href="https://fonts.googleapis.com/css?family=Playfair+Display:700,900" rel="stylesheet">
    
    <script src="https://code.jquery.com/jquery-3.2.1.slim.min.js"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.11.0/umd/popper.min.js"></script>
    <script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0-beta/js/bootstrap.min.js"></script>
    <link href="https://cdnjs.cloudflare.com/ajax/libs/summernote/0.8.11/summernote-bs4.css" rel="stylesheet">
    <script src="https://cdnjs.cloudflare.com/ajax/libs/summernote/0.8.11/summernote-bs4.js"></script>
</head>

<body>
    <div class="container">
        <header class="blog-header py-3">
            <div class="row flex-nowrap justify-content-between align-items-center">
                <div class="col-2 pt-1">
                    <img src="../img/supsi.png" id="supsilogo"/>
                </div>
                
                <div class="col-8 text-center" onclick="location.href = 'index.sh';">
                    <h1>Ambienti Operativi '19</h1>
                </div>
                <div class="col-2 d-flex justify-content-end align-items-center">
                    <!-- TODO: al click sulla lente deve essere caricata la pagina results.html -->
                    <!-- mostrante solo i posts che contengono il termine cercato -->
                    <form id="searchform" action="lookup.sh"><input id="search" name="keyword" placeholder="Cerca nel contenuto..."></input></form>
                    <a class="text-muted" href="#" onclick="document.getElementById('searchform').submit();">
                        <svg xmlns="http://www.w3.org/2000/svg" width="20" height="20" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round" class="mx-3"><circle cx="10.5" cy="10.5" r="7.5"></circle><line x1="21" y1="21" x2="15.8" y2="15.8"></line></svg>
                    </a>
                </div>
            </div>
        </header>
        
        <!-- TODO: qui devono apparire i 10 tags più usati -->
        <!-- al click su di un tag deve essere aperta la pagina results.html -->
        <!-- mostrante solo i posts che hanno un determinato tag -->
        <div class="nav-scroller py-1 mb-2">
            <nav class="nav d-flex justify-content-between">$MOST_USED_TAGS</nav>
        </div>
        
        <h1 class="bm25">Modifica post</h1>
        
        <form action="edit.sh?action=update&pid=$POST_ID" method="POST">
            <div class="form-group">
                <label>Titolo:</label>
                <input type="text" class="form-control" name="title" placeholder="" value="$POST_TITLE">
            </div>
            <div class="form-group">
                <label>Autore:</label>
                <input type="text" class="form-control" name="author" placeholder="" value="$POST_AUTHOR">
            </div>
            <div class="form-group">
                <label>Tags:</label>
                <input type="text" class="form-control" name="tags" placeholder="" value="$POST_TAGS">
                <small id="tagsHelp" class="form-text text-muted">I Tags vanno separati da spazi.</small>
            </div>
            <div class="form-group">
                <label>Contenuto:</label>
                <div id="content">
			<textarea class="form-control" rows="10" name="content">$POST_CONTENT</textarea>
		</div>
            </div>
            <button type="submit" class="btn btn-primary bm25" id="submitPost">Submit</button>
	    <a href="edit.sh?action=delete&pid=$POST_ID" class="btn btn-primary bm25" title="Elimina post">Elimina post</a> 
        </form>
    </div>
    
    <script>
        $(document).ready(function() {
            $('#content').summernote({
                height: 300
            });
        });
    </script>
    
    <footer class="blog-footer">
        <p>Ambienti Operativi - Istituto sistemi informativi e networking</p>
        <p>
            <a href="#">Torna in cima</a>
        </p>
    </div>
</body>
</html>
EOF

