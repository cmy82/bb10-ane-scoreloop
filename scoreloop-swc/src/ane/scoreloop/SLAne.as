package ane.scoreloop {
   import flash.external.ExtensionContext;
   
   public class SLAne {
      private var context:ExtensionContext;
      public var client:SLClient;
      
      public function SLAne() {
         context = ExtensionContext.createExtensionContext( "BSLLC.library.ane.ScoreLoop", null );
         
         client = new SLClient(context);
      }
   }
}