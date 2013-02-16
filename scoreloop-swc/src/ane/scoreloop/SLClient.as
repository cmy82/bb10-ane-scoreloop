package ane.scoreloop {
   import flash.external.ExtensionContext;
   
   public class SLClient {
      private var _context:ExtensionContext;
      
      public function SLClient(context:ExtensionContext) {
         _context = context;
      }
      
      public function createClient(id:String, secret:String, version:String, currency:String, languages:String):Number {
         var rslt:Object = _context.call( "sl_ane_SC_Client_New", id, id.length, secret, secret.length, version, version.length,
                                                                  currency, currency.length, languages, languages.length );
         return Number(rslt);
      }
   }
}