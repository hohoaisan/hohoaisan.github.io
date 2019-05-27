jQuery(function ($) {
	$('.table').footable({
		"paging": {
			"enabled": true,
			"limit": 3,
			"size": 20
		},
		"filtering": {
			"enabled": true
		},
		"sorting": {
			"enabled": true
		},
		"columns": [
			{ "name": "name", "title": "Tên" },
			{ "name": "group", "title": "Nhóm" },
			{ "name": "type", "title": "Kiểu" },
			{ "name": "ep", "title": "Số tập", "type": "text" },
			{ "name": "1080p",	"title": "FHD", "type": "link"},
			{ "name": "720p",	"title": "HD", "type": "link"},
			{ "name": "480p",	"title": "SD", "type": "link"
			}],

		"rows": $.get("/bakanime/docs/content/rows.json")
	});
});