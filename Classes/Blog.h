//
//  Blog.h
//  WordPress
//
//  Created by Gareth Townsend on 24/06/09.
//

#import <Foundation/Foundation.h>
#import <CommonCrypto/CommonDigest.h>

@interface Blog : NSManagedObject {
    NSString *_blavatarUrl;
}

@property (nonatomic, retain) NSNumber *blogID;
@property (nonatomic, retain) NSString *blogName, *url, *username, *password, *xmlrpc, *apiKey;
@property (readonly) NSString *hostURL;
@property (nonatomic, assign) NSNumber *isAdmin, *hasOlderPosts, *hasOlderPages;
@property (nonatomic, retain) NSSet *posts;
@property (nonatomic, retain) NSSet *categories;
@property (nonatomic, retain) NSSet *comments;
@property (nonatomic, assign) BOOL isSyncingPosts;
@property (nonatomic, assign) BOOL isSyncingPages;
@property (nonatomic, assign) BOOL isSyncingComments;
@property (nonatomic, retain) NSDate *lastPostsSync;
@property (nonatomic, retain) NSDate *lastPagesSync;
@property (nonatomic, retain) NSDate *lastCommentsSync;
@property (nonatomic, retain) NSDate *lastStatsSync;
@property (nonatomic, assign) BOOL geolocationEnabled;
@property (nonatomic, retain) NSDictionary *options; //we can store an NSArray or an NSDictionary as a transformable attribute... 
@property (nonatomic, retain) NSDictionary *postFormats;

- (BOOL)isWPcom;
- (void)dataSave;
- (NSString *)blavatarUrl;
- (NSArray *)sortedCategories;
- (NSString *)getOptionValue:(NSString *) name;

#pragma mark -
#pragma mark Synchronization
- (NSArray *)syncedPosts;
- (BOOL)syncPostsWithError:(NSError **)error loadMore:(BOOL)more;
- (BOOL)syncPagesWithError:(NSError **)error loadMore:(BOOL)more;
- (BOOL)syncCategoriesWithError:(NSError **)error;
- (BOOL)syncOptionsWithError:(NSError **)error;
- (BOOL)syncCommentsWithError:(NSError **)error;
- (BOOL)syncPostFormatsWithError:(NSError **)error; 
- (NSString *) returnMD5Hash:(NSString*)concat;

#pragma mark -
#pragma mark Class methods
+ (BOOL)blogExistsForURL:(NSString *)theURL withContext:(NSManagedObjectContext *)moc andUsername:(NSString *)username;
+ (Blog *)createFromDictionary:(NSDictionary *)blogInfo withContext:(NSManagedObjectContext *)moc;
+ (NSInteger)countWithContext:(NSManagedObjectContext *)moc;

@end
