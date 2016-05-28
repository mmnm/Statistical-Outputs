
var Game = require('./game');

if (process.argv.length != 5) {
  process.stderr.write("usage: " + process.argv[1] + " <width>, <height> <mine_count>\n");
  process.exit(1);
}

var width = process.argv[2];
var height = process.argv[3];
var mine_count = process.argv[4];

var game = new Game(width, height, mine_count);

var buf = '';
process.stdin.on('data', function(chunk) {
  buf = buf + chunk;
  var lines = buf.split(/\r?\n/);
  buf = lines.pop();
  lines.forEach(function(line) {
    var parts = line.trim().split(/\s+/);
    if (parts.length != 3) {
      process.stderr.write("unknown command " + line + "\n");
      return;
    }

    var cmd = parts[0];
    var x = parseInt(parts[1], 10);
    var y = parseInt(parts[2], 10);
    if (parts[0] == "reveal") {
      var count = game.reveal(x, y);
      process.stdout.write("" + count + "\n");
    } else {
      process.stderr.write("unknown command " + line + "\n");
    }
  });
});
