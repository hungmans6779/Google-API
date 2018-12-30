<?php
    // 發送Header，表明是PNG文件
    header('content-type: image/png');
    
    // 設置源圖片的路徑並創建
    $src = 'http://mapgoogle.mapabc.com/googlechina/maptile?v=w2.60&' . $_SERVER["QUERY_STRING"];
    $image = imagecreatefromgif($src);
    
    
    // 需要被清除的顏色 數組
    $removedcollors = array(
                            imagecolorexact($image, 152, 178, 203),
                            imagecolorexact($image, 241, 238, 232),
                            imagecolorexact($image, 232, 227, 216),
                            imagecolorexact($image, 235, 230, 220),
                            imagecolorexact($image, 242, 239, 233)
                           );
    
    // 設定透明色
    $transparent = imagecolorallocate($image, 100, 100, 100);
    
    // 獲取圖片大小，以便逐點清除顏色
    $x = imagesx($image);
    $y = imagesy($image);
    
    // 清除顏色
    for($i = 0; $i<$x; $i++)
    {
        for($j = 0; $j<$y; $j++)
        {
            $color = imagecolorat($image, $i, $j);
            if(in_array($color, $removedcollors))
            {
                imagesetpixel($image, $i, $j, $transparent);
            }
        }
    }
    
    // 設置圖片透明
    imagecolortransparent($image, $transparent);
    
    // 輸出PNG圖片
    imagepng($image);
    
    // 銷毀圖片資源
    imagedestroy($image);
?>
