
		jQuery(function ($) {
			$('.table').footable({
				"paging": {
					"enabled": true,
					"limit": 10,
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
					{ "name": "status", "title": "Tình trạng" },
					{ "name": "ep", "title": "Số tập", "type": "text" },
					{
						"name": "1080p1",
						"title": "FHD",
						"formatter": function (value) {
							if (value != '') { value = '<a href="' + value + '" target="_blank"> FHD </a>'; }
							return value;
						}
					},
					{
						"name": "1080p2",
						"title": "FHD",
						"formatter": function (value) {
							if (value != '') { value = '<a href="' + value + '" target="_blank"> FHD </a>'; }
							return value;
						}
					},
					{
						"name": "720p1",
						"title": "HD",
						"formatter": function (value) {
							if (value != '') { value = '<a href="' + value + '" target="_blank"> HD </a>'; }
							return value;
						}
					},
					{
						"name": "720p2",
						"title": "HD",
						"formatter": function (value) {
							if (value != '') { value = '<a href="' + value + '" target="_blank"> HD </a>'; }
							return value;
						}
					},
					{
						"name": "480p1",
						"title": "SD",
						"formatter": function (value) {
							if (value != '') { value = '<a href="' + value + '" target="_blank"> SD </a>'; }
							return value;
						}
					},
					{
						"name": "480p2",
						"title": "SD",
						"formatter": function (value) {
							if (value != '') { value = '<a href="' + value + '" target="_blank"> SD </a>'; }
							return value;
						}
					}],
					
				"rows": $.get("docs/content/rows.json")
			});
		});