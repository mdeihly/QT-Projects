import QtQuick 2.15

Item {
    id: root

    property int lineWidth: 5
    property real progress: 0 // Progress value between 0 and 1

    onProgressChanged: {
        canvas.degree = progress * 360;
    }

    Canvas {
        id: canvas

        property real degree: 0

        anchors.fill: parent

        onDegreeChanged: {
            requestPaint();
        }

        // handler to override for drawing
        onPaint: {

            // get context to draw with
            var ctx = getContext("2d");
            ctx.reset();

            var x = canvas.width/2;
            var y = canvas.height/2;

            var radius = canvas.width/2 - root.lineWidth
            var startAngle = (Math.PI/180) * 270;
            var fullAngle = (Math.PI/180) * (270 + 360);
            var progressAngle = (Math.PI/180) * (270 + degree);

            // draw background circle
            ctx.beginPath();
            ctx.arc(x, y, radius, startAngle, fullAngle);
            // setup the stroke
            ctx.lineWidth = root.lineWidth;
            ctx.strokeStyle = 'lightgrey';
            // stroke using line width and stroke style
            ctx.stroke();

            // draw progress arc
            ctx.beginPath();
            ctx.arc(x, y, radius, startAngle, progressAngle);
            // setup the stroke
            ctx.strokeStyle = 'blue';
            // stroke using line width and stroke style
            ctx.stroke();
        }
    }
}
