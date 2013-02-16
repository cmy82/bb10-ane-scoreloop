package {
   import ane.scoreloop.SLAne;
   
   import flash.desktop.NativeApplication;
   import flash.desktop.SystemIdleMode;
   
   import flash.display.Sprite;
   import flash.display.StageAlign;
   import flash.display.StageScaleMode;
   
   public class SLANETest extends Sprite {
      private var slane:SLAne;
      
      [SWF(frameRate="30")]
      public function SLANETest() {
         super();
         
         slane = new SLAne();
         var out:Number = 
         slane.client.createClient("a5e395dc-53b5-47d2-b3e9-20f8ce2f122e",
                                   "vdntD+pLMabbl51aROz3XSyBg8NerTs/U+lSY1v+X3MA4GHv4v8eeQ==",
                                   "1.0", " 	IYI", "en");
         
         trace(out);
         
         // support autoOrients
         stage.align = StageAlign.TOP_LEFT;
         stage.scaleMode = StageScaleMode.NO_SCALE;         
         stage.nativeWindow.visible = true;
         NativeApplication.nativeApplication.systemIdleMode = SystemIdleMode.KEEP_AWAKE;
      }
   }
}