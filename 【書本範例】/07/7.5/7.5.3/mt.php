<?php
    // �o�eHeader�A����OPNG���
    header('content-type: image/png');
    
    // �]�m���Ϥ������|�óЫ�
    $src = 'http://mapgoogle.mapabc.com/googlechina/maptile?v=w2.60&' . $_SERVER["QUERY_STRING"];
    $image = imagecreatefromgif($src);
    
    
    // �ݭn�Q�M�����C�� �Ʋ�
    $removedcollors = array(
                            imagecolorexact($image, 152, 178, 203),
                            imagecolorexact($image, 241, 238, 232),
                            imagecolorexact($image, 232, 227, 216),
                            imagecolorexact($image, 235, 230, 220),
                            imagecolorexact($image, 242, 239, 233)
                           );
    
    // �]�w�z����
    $transparent = imagecolorallocate($image, 100, 100, 100);
    
    // ����Ϥ��j�p�A�H�K�v�I�M���C��
    $x = imagesx($image);
    $y = imagesy($image);
    
    // �M���C��
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
    
    // �]�m�Ϥ��z��
    imagecolortransparent($image, $transparent);
    
    // ��XPNG�Ϥ�
    imagepng($image);
    
    // �P���Ϥ��귽
    imagedestroy($image);
?>
